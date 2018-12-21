/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (27.96%)
 * Total Accepted:    140.9K
 * Total Submissions: 504K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
	//this is a Classic Dynamic Promgramming problem, but why you even think about n - d[i]?
	//your goal is to move the get the final answer d[n] !! as d[0] = 0!!!
	// the transision is d[i] = min(d[i], d[i - coins[j] + 1), in which j is you need to 
	// try every possible move in the coins from last state
	int max_n = amount + 1; //all the combinations of 1 and plus 1
	vector<int> d(amount + 1, max_n);
	d[0] = 0;
	for(int i = 1; i <= amount; i++)
	{
	    for(int j = 0; j < coins.size(); j++)
	    {
		if(i >= coins[j])
		    //if we have answer at amount, then d[i] will be a number less than max_n
		    d[i] = min(d[i], d[i - coins[j]] + 1);  	    }
	}

	return d[amount] >= max_n ? -1 : d[amount]; //if less than max_n, then must be updated with answer
    }
};
