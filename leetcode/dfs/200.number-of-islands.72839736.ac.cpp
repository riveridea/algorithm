/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (38.27%)
 * Total Accepted:    234.6K
 * Total Submissions: 613K
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
        //depth first search 
        //traverse every point with non-zero value
        //each point, after it is traversed, set the value to -1 
        //to avoid repeated traverse.
        //finally the returned count is the result
        int result = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1'){
                    result++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return result;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        grid[i][j] = -1; //important, firstly disable this point
        if(i+1 < grid.size() && grid[i+1][j] == '1') dfs(i+1, j, grid);
        if(j+1 < grid[i].size() && grid[i][j+1] == '1') dfs(i, j+1, grid);
        if(i-1 < grid.size() && grid[i-1][j] == '1') dfs(i-1, j, grid);
        if(j-1 < grid[i].size() && grid[i][j-1] == '1') dfs(i, j-1, grid);
    }
};
