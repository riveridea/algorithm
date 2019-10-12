/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 *
 * https://leetcode.com/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (37.07%)
 * Total Accepted:    10.1K
 * Total Submissions: 27.2K
 * Testcase Example:  '3'
 *
 * We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape.
 * These shapes may be rotated.
 * 
 * 
 * XX  <- domino
 * 
 * XX  <- "L" tromino
 * X
 * 
 * 
 * Given N, how many ways are there to tile a 2 x N board? Return your answer
 * modulo 10^9 + 7.
 * 
 * (In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.)
 * 
 * 
 * 
 * Example:
 * Input: 3
 * Output: 5
 * Explanation: 
 * The five different ways are listed below, different letters indicates
 * different tiles:
 * XYZ XXZ XYY XXY XYY
 * XYZ YYZ XZZ XYY XXY
 * 
 * Note:
 * 
 * 
 * N  will be in range [1, 1000].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int numTilings(int N) {
        //dp[i] = 2*dp[i-1] + dp[i-3]
        const int MOD = 1e9 + 7;
        vector<long> dp = {0, 1, 2, 5};
        
        int i = 4;
        for(; i <= N; ++i){
            dp[i%4] = 2*dp[(i-1)%4] + dp[(i-3)%4];
            dp[i%4] %= MOD;
        }
        return dp[N%4];
    }
};
