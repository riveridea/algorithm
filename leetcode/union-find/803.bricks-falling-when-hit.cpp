/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 *
 * https://leetcode.com/problems/bricks-falling-when-hit/description/
 *
 * algorithms
 * Hard (29.15%)
 * Total Accepted:    11.3K
 * Total Submissions: 38.9K
 * Testcase Example:  '[[1,0,0,0],[1,1,1,0]]\n[[1,0]]'
 *
 * We have a grid of 1s and 0s; the 1s in a cell represent bricks.  A brick
 * will not drop if and only if it is directly connected to the top of the
 * grid, or at least one of its (4-way) adjacent bricks will not drop.
 * 
 * We will do some erasures sequentially. Each time we want to do the erasure
 * at the location (i, j), the brick (if it exists) on that location will
 * disappear, and then some other bricks may drop because of that erasure.
 * 
 * Return an array representing the number of bricks that will drop after each
 * erasure in sequence.
 * 
 * 
 * Example 1:
 * Input: 
 * grid = [[1,0,0,0],[1,1,1,0]]
 * hits = [[1,0]]
 * Output: [2]
 * Explanation: 
 * If we erase the brick at (1, 0), the brick at (1, 1) and (1, 2) will drop.
 * So we should return 2.
 * 
 * 
 * Example 2:
 * Input: 
 * grid = [[1,0,0,0],[1,1,0,0]]
 * hits = [[1,1],[1,0]]
 * Output: [0,0]
 * Explanation: 
 * When we erase the brick at (1, 0), the brick at (1, 1) has already
 * disappeared due to the last move. So each erasure will cause no bricks
 * dropping.  Note that the erased brick (1, 0) will not be counted as a
 * dropped brick.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of rows and columns in the grid will be in the range [1,
 * 200].
 * The number of erasures will not exceed the area of the grid.
 * It is guaranteed that each erasure will be different from any other erasure,
 * and located inside the grid.
 * An erasure may refer to a location with no brick - if it does, no bricks
 * drop.
 * 
 * 
 */
class disjoint_unit {
    vector<int> parent;
    vector<int> sz;

public:
    disjoint_unit(int n){
	parent.resize(n, 0);
	for(int i = 0; i < n; i++)
	{
	    parent[i] = i;
	}

	sz.resize(n, 1);
    }

    int find(int x){
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
    }

    void union_set(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b)
	{
	    if(sz[a] < sz[b])
		swap(a, b);

	    parent[b] = a;
	    sz[a] += sz[b];
	}
    }

    int top_size(){
	return sz[find(sz.size() - 1)] - 1; //should remove the R*C itself
    }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
	//union find, but use the union find by size 
	//firstly we cut the hits and compute the size of each set
	//all the sets connect to the top will be union to the R*C as one set
	//then we add the hits back to see if size change of the set connected 
	//to the top, the change is the answer for each hit
	int r_size = grid.size();
	int c_size = grid[0].size();
	int dr[4] = {1, 0, -1, 0};
	int dc[4] = {0, 1, 0, -1};

	vector<vector<int>> copy_grid = grid;
	for(auto hit : hits)
	{
	    copy_grid[hit[0]][hit[1]] = 0; //cut this point firstly
	}

	disjoint_unit dsu(r_size*c_size + 1); //the extra one is for R*C
	for (int r = 0; r < r_size; r++){
	    for(int c = 0; c < c_size; c++){
		if(copy_grid[r][c] == 1){
		    int pos = r*c_size + c;
		    if(r == 0) 
			dsu.union_set(pos, r_size*c_size);
		    if(r > 0 && copy_grid[r-1][c] == 1)
			dsu.union_set(pos, (r-1)*c_size + c);
		    if(c > 0 && copy_grid[r][c-1] == 1)
			dsu.union_set(pos, r*c_size + c-1);
		}
	    }
	}

	int t = hits.size();
	vector<int> ans(t, 0);
	//now add the hit back from last hit
	while(--t >= 0){
	    int a = hits[t][0];
	    int b = hits[t][1];

	    if(grid[a][b] == 0) continue; //it was the 0, no affect
	    int pos = a*c_size + b;
	    int pre_roof = dsu.top_size();
	    //cout << "pre_roof=" << pre_roof << endl;
	    //union the hit's adjacents
	    for(int k = 0; k < 4; k++)
	    {
		int rk = a + dr[k];
		int ck = b + dc[k];
		if(rk >= 0 && rk < r_size && ck >= 0 && ck < c_size && copy_grid[rk][ck] == 1)
		{
		    int posk = rk*c_size + ck; 
		    dsu.union_set(pos, posk);
		}
	    }

	    if(a == 0) //don't forget if it is hit on top
		dsu.union_set(pos, r_size*c_size);
	    
	    copy_grid[a][b] = 1; //add back
	    ans[t] = max(0, dsu.top_size() - pre_roof - 1);
	    //cout << "ans[" << t << "]" << ans[t] << endl;
	}

	return ans;
    }
};


