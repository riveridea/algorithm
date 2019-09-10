/*
 * @lc app=leetcode id=694 lang=cpp
 *
 * [694] Number of Distinct Islands
 *
 * https://leetcode.com/problems/number-of-distinct-islands/description/
 *
 * algorithms
 * Medium (52.35%)
 * Total Accepted:    31.8K
 * Total Submissions: 60.7K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.)  You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Count the number of distinct islands.  An island is considered to be the
 * same as another if and only if one island can be translated (and not rotated
 * or reflected) to equal the other.
 * 
 * Example 1:
 * 
 * 11000
 * 11000
 * 00011
 * 00011
 * 
 * Given the above grid map, return 1.
 * 
 * 
 * Example 2:
 * 11011
 * 10000
 * 00001
 * 11011
 * Given the above grid map, return 3.
 * Notice that:
 * 
 * 11
 * 1
 * 
 * and
 * 
 * ⁠1
 * 11
 * 
 * are considered different island shapes, because we do not consider
 * reflection / rotation.
 * 
 * 
 * Note:
 * The length of each dimension in the given grid does not exceed 50.
 * 
 */
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
	//dfs, hash by the path, using the string
	for(int i = 0; i < grid.size(); i++){
	    for(int j = 0; j < grid[0].size(); j++){
		if(grid[i][j] != 0){
		    //start DFS
		    string sb;
		    dfs(grid, i, j, sb, "o");
		    //set this grid as 0 after visited
		    grid[i][j] = 0;
		    islands.insert(sb);
		}
	    }
	}	
	return islands.size();
    }
private:
    unordered_set<string> islands;
    void dfs(vector<vector<int>>& grid, int i, int j, string& sb, string dir){
	if(i < 0 || i == grid.size() || j < 0 || j == grid[i].size() || grid[i][j] == 0)
	    return;


	sb += dir; 
	grid[i][j] = 0; //mark as visisted
	//start dfs for the ajacnet nodes
	dfs(grid, i-1, j, sb, "u");
	dfs(grid, i+1, j, sb, "d");
	dfs(grid, i, j-1, sb, "l");
	dfs(grid, i, j+1, sb, "r");

	sb += "b"; //mark as back
    }
};



























































































