/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (36.81%)
 * Total Accepted:    38.9K
 * Total Submissions: 105.6K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows:
 * 
 * I pick a number from 1 to n. You have to guess which number I picked.
 * 
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower.
 * 
 * However, when you guess a particular number x, and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 * 
 * Example:
 * 
 * 
 * n = 10, I pick 8.
 * 
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 * 
 * Game over. 8 is the number I picked.
 * 
 * You end up paying $5 + $7 + $9 = $21.
 * 
 * 
 * Given a particular n ≥ 1, find out how much money you need to have to
 * guarantee a win.
 */
class Solution {
public:
    int getMoneyAmount(int n) {
	//this is a 2D dp problem, dp(i, j) means the minimum cost during i and j if make sure win
	//and we need to find a pivot [i+1, j-1] which can minimze the cost,
	//at the privot, if we lost, we cost pivot, and for dp[i, pivot-1] and dp[pivot+1, j], we 
	//need choose max(dp[i, pivot-1], dp[pivot+1, j]), because the larger one can cover the the cost
	//for the smaller range.
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for(int i = 2; i <= n; i++)
	{
	    for(int j = i-1; j > 0; j--)
	    {
		//dp(j,i), try all pivot to find the minimum cost
		int global_min = INT_MAX;
		for(int pivot = (i+j)/2; pivot < i; pivot++) // small optimization, as the pivot on the left side always return the right as bigger
		//for(int pivot = (i+j)/2; pivot < i; pivot++)
		{
		    global_min = min(global_min, pivot+max(dp[j][pivot-1], dp[pivot+1][i])); 
		}
		dp[j][i] = j == i-1 ? j : global_min;  // dp[i-1][i] = i-1 is very important, as this is start value
	    }
	}
	return dp[1][n];
    }
};



