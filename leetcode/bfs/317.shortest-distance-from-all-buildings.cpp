/*
 * [317] Shortest Distance from All Buildings
 *
 * https://leetcode.com/problems/shortest-distance-from-all-buildings/description/
 *
 * algorithms
 * Hard (35.78%)
 * Total Accepted:    31.3K
 * Total Submissions: 87.4K
 * Testcase Example:  '[[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]'
 *
 * You want to build a house on an empty land which reaches all buildings in
 * the shortest amount of distance. You can only move up, down, left and right.
 * You are given a 2D grid of values 0, 1 or 2, where:
 * 
 * 
 * Each 0 marks an empty land which you can pass by freely.
 * Each 1 marks a building which you cannot pass through.
 * Each 2 marks an obstacle which you cannot pass through.
 * 
 * 
 * Example:
 * 
 * 
 * Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
 * 
 * 1 - 0 - 2 - 0 - 1
 * |   |   |   |   |
 * 0 - 0 - 0 - 0 - 0
 * |   |   |   |   |
 * 0 - 0 - 1 - 0 - 0
 * 
 * Output: 7 
 * 
 * Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle
 * at (0,2),
 * ⁠            the point (1,2) is an ideal empty land to build a house, as the
 * total 
 * travel distance of 3+3+1=7 is minimal. So return 7.
 * 
 * Note:
 * There will be at least one building. If it is not possible to build such
 * house according to the above rules, return -1.
 * 
 */
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
	//this is actually simple BFS, but the idea is
	//start from each building to compute the shortest distance for each
	//empty land
	//for for each building, BFS will update the distance for each 
	//empty land, and at last the minimum distance that empty land has
	//is returned.
	//As each empty land has 0 mark, thus each BFS will decrease 1 meaning 
	//this empty land has been BFSed by one building, a variable is used to mark
	//this, so weather this is an empty land is marked by grid[i][j] == visits
	if(grid.empty()) return 0;
	int m = grid.size();
	int n = grid[0].size();
	auto accumulate = grid;

	int visits = 0; 
	int updates[] = {0, 1, 0, -1};
	int min_distance = -1;
	//traversal every building to do BFS
	for(int i = 0; i < m; i++)	
	{
	    for(int j = 0; j < n; j++)
	    {
		//only check building
		if(grid[i][j] == 1)
		{
		    min_distance = -1; //visits will mark all the empty as not accessed if no solution
		    vector<vector<int>> distance(m);
		    for(int l = 0; l < m; l++)
		    {
			distance[l].resize(n,0);
		    }
		    queue<pair<int, int>> q; // queue used for BFS
		    q.push(pair<int,int>(i, j));
		    while(!q.empty())
		    {
			pair<int, int> node = q.front();
			q.pop();	
			//check the four derections
			for(int k = 0; k < 4; k++)
			{
			    int x = node.first + updates[k];
			    int y = node.second + updates[(k+1)%4];
			    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == visits)  
			    {
				grid[x][y]--; //decrease the visists,finish this building for this empty land
				distance[x][y] = distance[node.first][node.second] + 1;
				accumulate[x][y] += distance[x][y];
				q.push(pair<int,int>(x,y));
				//cout << min_distance << " " << accumulate[x][y] << "[" << x << "]" << "[" << y << "]";
				if( min_distance < 0 ||  min_distance > accumulate[x][y])
				{
				    min_distance = accumulate[x][y];
				}
			    }
			}
		    }  
		    visits--;  
		}
	    }
	}
	return min_distance;
    }
};
