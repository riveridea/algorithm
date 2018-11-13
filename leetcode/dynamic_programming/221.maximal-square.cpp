/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (31.45%)
 * Total Accepted:    106.9K
 * Total Submissions: 339.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
	//the hardest thing is to find the tranformation state transition formulat
	//define dp[i][j] as the max edge size (all 1) at posiito i(row), j(column)
	//then if matrix[i][j] == 0, then dp[i][j] = 0
	//if matrix[i][j] == 1, then dp[i][j] = min{dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}+1        
	int m = matrix.size(); //rows
	if (m == 0) return 0;
	int n = matrix[0].size();
	if (n == 0) return 0;

	int sz = 0;
	vector<vector<int>> dp(m, vector<int>(n,0));

	//initialize the first row
	for(int j=0; j<n; j++)
	{
	    dp[0][j] = (matrix[0][j] == '1')? 1:0;	
	    sz = max(sz, dp[0][j]);
	}
	//initialize the first column
	for(int i=0; i<m; i++)
	{
	    dp[i][0] = (matrix[i][0] == '1')? 1:0;	
	    sz = max(sz, dp[i][0]);
	}

	//start dp
	for(int i = 1; i < m; i++)
	{
	    for(int j = 1; j < n; j++)
	    {
		if(matrix[i][j] == '1')
		{
		    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
		    sz = max(sz, dp[i][j]);
		}
		else
		{
		    dp[i][j] = 0;
		}
	    }
	}

	return sz*sz;
    }
};
