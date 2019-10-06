/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 *
 * https://leetcode.com/problems/predict-the-winner/description/
 *
 * algorithms
 * Medium (47.12%)
 * Total Accepted:    56.1K
 * Total Submissions: 119.1K
 * Testcase Example:  '[1,5,2]'
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one
 * of the numbers from either end of the array followed by the player 2 and
 * then player 1 and so on. Each time a player picks a number, that number will
 * not be available for the next player. This continues until all the scores
 * have been chosen. The player with the maximum score wins. 
 * 
 * Given an array of scores, predict whether player 1 is the winner. You can
 * assume each player plays to maximize his score. 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2. If he chooses 2
 * (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5,
 * then player 1 will be left with 1 (or 2). So, final score of player 1 is 1 +
 * 2 = 3, and player 2 is 5. Hence, player 1 will never be the winner and you
 * need to return False.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between
 * 5 and 7. No matter which number player 2 choose, player 1 can choose
 * 233.Finally, player 1 has more score (234) than player 2 (12), so you need
 * to return True representing player1 can win.
 * 
 * 
 * 
 * Note:
 * 
 * 1 
 * Any scores in the given array are non-negative integers and will not exceed
 * 10,000,000.
 * If the scores of both players are equal, then player 1 is still the winner.
 * 
 * 
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        //this is actually very hard DP problem as my understanding
        //please refer to https://leetcode.com/problems/predict-the-winner/discuss/96832/C%2B%2B-DP-solution-with-explanation
        //dp[i][j] was supposed to be the maximum score of the current round's first player's
        //maximum score between nums[i] and nums[j] inclusive, but with some deduction it becomes the dp'[i][j] which measn the 
        //diff of first player and second player, once getting the dp[0][n-1], we check it is
        //positive or negative
        //dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
        int n = nums.size();
        if(n == 0) return false;

        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i<n; i++) dp[i][i] = nums[i];

        for(int s = n-2; s >= 0; s--){ // you should start from rear to use the known value
            for(int e = s+1; e < n; e++){
                dp[s][e] = max(nums[s]-dp[s+1][e], nums[e]-dp[s][e-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};
