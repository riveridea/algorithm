/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (46.95%)
 * Total Accepted:    69.5K
 * Total Submissions: 147.9K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
class Solution {
public:
    int integerBreak(int n) {
	//a rule, for n > 6, the solution is 3*dp[n-3], where dp[n] means the solution at n
	//about this proof of this solution, you need to take derivative as zero ....search it.
	vector<int>  dp(7, 0);
	dp[2] = 1; // 1*1
	dp[3] = 2; //1*2
	dp[4] = 4;  //2*2
	dp[5] = 6; //3*2
	dp[6] = 9; //3*3

	//bottom up DP
	for(int i = 7; i <= n; i++)
	{
	    dp[i%7] = 3*dp[(i-3)%7];
	    //cout << "dp["<< i << "]" << dp[i%7];
	}
	return  dp[n%7];
    }
};
