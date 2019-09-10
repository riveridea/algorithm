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







































































