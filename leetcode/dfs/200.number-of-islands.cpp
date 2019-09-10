/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (42.73%)
 * Total Accepted:    417.9K
 * Total Submissions: 977.8K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
	//dfs, with mark the visited in the original grid      
	int result = 0;
	for(int i = 0; i < grid.size(); i++){
	    for(int j = 0; j < grid[0].size(); j++){
		if(grid[i][j] == '1'){
		    result++;
		    dfs(i, j, grid);
		}
	    }
	}
	return result;
    }
private:
    void dfs(int i, int j, vector<vector<char>>& grid){
	if(i < 0 || i == grid.size() || j < 0 || j == grid[i].size() || grid[i][j] != '1')
	    return;
	
	grid[i][j] = 0;
	//start dfs for all the adjacent nodes
	dfs(i+1, j, grid);
	dfs(i-1, j, grid);
	dfs(i, j+1, grid);
	dfs(i, j-1, grid);
    }
};
















































