/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (42.69%)
 * Total Accepted:    74.1K
 * Total Submissions: 173.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
	//O(n) dynamic programming
	//define 
	//sell[i] - this day we either sell or cooldown (does not hold), the maximum profit at this day
	//buy[i] - this day we hold the stock, the maximum profit at this day
	//sell[i] = max{buy[i-1]+prices[i], sell[i-1]};
	//buy[i] = max{sell[i-2] - prices[i], buy[i-1] }
	//the solution is in sell[n-1]
    }
};
