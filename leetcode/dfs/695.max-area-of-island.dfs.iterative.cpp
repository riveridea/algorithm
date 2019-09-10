/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (58.59%)
 * Total Accepted:    96.7K
 * Total Submissions: 164.9K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 * 
 * Example 1:
 * 
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 * 
 * Example 2:
 * 
 * 
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * 
 * Note: The length of each dimension in the given grid does not exceed 50.
 * 
 */
#if 0
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
	//let's try the recursive dfs firstly
	int ans = 0;
	for(int i = 0; i < grid.size(); i++){
	    for(int j = 0; j < grid[i].size(); j++){
		if(grid[i][j] != 0) 
		    ans = max(ans, dfs(i, j, grid));
	    }
	}
	return ans;
    }
private:
    int dfs(int i, int j, vector<vector<int>>& grid){
	if(i < 0 || j < 0 || i == grid.size() || j == grid[i].size() || grid[i][j] == 0)
	    return 0;
	
	grid[i][j] = 0;

	return dfs(i, j+1, grid) +
	       dfs(i, j-1, grid) +
	       dfs(i+1, j, grid) +
	       dfs(i-1, j, grid) +
	       1;
    }
};
#endif

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
	//let's try the iterative dfs 
	int ans = 0;
	for(int i = 0; i < grid.size(); i++){
	    for(int j = 0; j < grid[i].size(); j++){
		if(grid[i][j] == 1){ 
		    cout << i << "~" << j <<"->";
		    ans = max(ans, dfs(i, j, grid));
		}
	    }
	}
	return ans;
    }
private:
    int dfs(int i, int j, vector<vector<int>>& grid){
	//need a stack 
	//need a value to record of the number of points traversed for each dfs
	//please not any time the point is pushed to stack, mark the point as visited!!
	stack<vector<int>> s;
	vector<int> root({i, j});
	s.push(root);
	grid[i][j] = 0;
	int area = 0;
	//static int count = 0;
	while(!s.empty()){
	    vector<int>	p = s.top(); s.pop();
	    area++;
	    int r = p[0], c = p[1];
	    //cout << r << "-" << c << ",";
	    if(r+1 < grid.size() && grid[r+1][c] == 1)
	    {
		s.push({r+1, c});
		grid[r+1][c] = 0;
	    }
	    if(r-1 >= 0 && grid[r-1][c] == 1)
	    {
		s.push({r-1, c});
		grid[r-1][c] = 0;
	    }
	    if(c+1 < grid[0].size() && grid[r][c+1] == 1)
	    { 
		s.push({r, c+1});
		grid[r][c+1] = 0;
	    }
	    if(c-1 >= 0 && grid[r][c-1] == 1)
	    { 
		s.push({r, c-1});
		grid[r][c-1] = 0;
	    }
	}
	return area;
    }
};







































































