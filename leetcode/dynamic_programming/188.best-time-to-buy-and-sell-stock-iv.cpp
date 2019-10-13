/*
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
 *
 * algorithms
 * Hard (24.64%)
 * Total Accepted:    54.2K
 * Total Submissions: 219.8K
 * Testcase Example:  '2\n[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //DP
        //dp[i][j] - maximum profit from at the most i transactions using prices[0..j]
        //at day j we have options:
        //1. hold - d[i][j] = dp[i][j-1] the profit doesn't change
        //2. buy - don't need to put into DP, as the profit is decreased
        //3. sell - if sell at day j, it means last buy occure during t in prices[0..j-1] , 
        //   we will have dp[i][j] = max(price[j] - price[t] + dp[i-1][t-1]) 
        //                         = price[j] + max(dp[i-1][t-1] - price[t]), while 0 <= t <= j-1
        int m = prices.size();
        if(!m) return 0;
       
        // buy and sell calls 1 transcation, so if k > m/2, just do as you wish
        if(k > m/2) {
            int maxPro = 0;
		    for (int i = 1; i < m; i++) {
			    if (prices[i] > prices[i-1])
				    maxPro += prices[i] - prices[i-1];
		        }
		    return maxPro;
        }

        vector<vector<int>> dp(k+1, vector<int>(m));
        for(int i = 1; i <= k; i++){
            int last_max = -prices[0]; //j == 0
            for(int j = 1; j < m; j++){
                //last_max is kept updated for 0 - j-1
                dp[i][j] = max(dp[i][j-1], prices[j] + last_max);
                last_max = max(last_max, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][m-1];
    }
};
