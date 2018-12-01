/*
 * [361] Bomb Enemy
 *
 * https://leetcode.com/problems/bomb-enemy/description/
 *
 * algorithms
 * Medium (41.66%)
 * Total Accepted:    28.8K
 * Total Submissions: 69.1K
 * Testcase Example:  '[["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]'
 *
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0'
 * (the number zero), return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted
 * point until it hits the wall since the wall is too strong to be destroyed.
 * Note: You can only put the bomb at an empty cell.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
 * Output: 3 
 * Explanation: For the given grid,
 * 
 * 0 E 0 0 
 * E 0 W E 
 * 0 E 0 0
 * 
 * Placing a bomb at (1,1) kills 3 enemies.
 * 
 * 
 */
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
	//this is a kind of array problem actuall
	int m = grid.size();        
	if (m == 0) return 0;
	int n = grid[0].size();
	if (n == 0) return 0;

	int rowcnt = 0, res = 0;
	vector<int> colcnt(n, 0);

	for(int i = 0; i < m; i++)
	{
	    for(int j = 0; j < n; j++)
	    {
		//at row i, we only need to update the killed enemies when 
		//at the edge or just across a wall
		if(j == 0 || grid[i][j-1] == 'W')
		{
		    rowcnt = 0;
		    for(int k = j ; k < n && grid[i][k] != 'W'; k++) 
		    {
			rowcnt += grid[i][k] == 'E' ? 1 : 0;
		    }
		}
		
		//now as we reach column j
		//we may need to record the killed enemies only if
		//when we at the colun edge or just across the wall
		//a colum array is used as when we go to next row but 
		//back to this j, we can reuse the colcnt[j] if possible
		//unless new conditions lead to update of colcnt[j]
		if(i == 0 || grid[i-1][j] == 'W')
		{
		    colcnt[j] = 0;
		    for(int k = i; k < m && grid[k][j] != 'W'; k++)
		    {
			colcnt[j] += grid[k][j] == 'E' ? 1 : 0;
		    }
		}

		//for all the points of none edge and none just across wall, 
		//just reuse the rowcnt and colcnt[j]
		if(grid[i][j] == '0')
		{
		    res = max(res, rowcnt + colcnt[j]); 
		}
	    }
	}
	return res;
    }
};
