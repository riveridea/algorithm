/*
 * @lc app=leetcode id=750 lang=cpp
 *
 * [750] Number Of Corner Rectangles
 *
 * https://leetcode.com/problems/number-of-corner-rectangles/description/
 *
 * algorithms
 * Medium (65.42%)
 * Total Accepted:    21.6K
 * Total Submissions: 33K
 * Testcase Example:  '[[0,1,0],[1,0,1],[1,0,1],[0,1,0]]'
 *
 * Given a grid where each entry is only 0 or 1, find the number of corner
 * rectangles.
 * 
 * A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned
 * rectangle. Note that only the corners need to have the value 1. Also, all
 * four 1s used must be distinct.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = 
 * [[1, 0, 0, 1, 0],
 * ⁠[0, 0, 1, 0, 1],
 * ⁠[0, 0, 0, 1, 0],
 * ⁠[1, 0, 1, 0, 1]]
 * Output: 1
 * Explanation: There is only one corner rectangle, with corners grid[1][2],
 * grid[1][4], grid[3][2], grid[3][4].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = 
 * [[1, 1, 1],
 * ⁠[1, 1, 1],
 * ⁠[1, 1, 1]]
 * Output: 9
 * Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and
 * one 3x3 rectangle.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = 
 * [[1, 1, 1, 1]]
 * Output: 0
 * Explanation: Rectangles must have four distinct corners.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of rows and columns of grid will each be in the range [1,
 * 200].
 * Each grid[i][j] will be either 0 or 1.
 * The number of 1s in the grid will be at most 6000.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        //no matter use the common find and match or the dynamic programming
        //there is a basic idea
        //no one row, let's say i, we got a pair of 1s, on column c1, c2
        //each time we go a new pair, we increment the answer firlsty (adding the occurrence),
        //then update the occurence, in this way the answer will reflect the actuall rectangle
        //appears
        //in dp, the occurence can be represented by dp[c1][c2]
        //or in hashmap just map[c1*200+c2] 

        //now use the dp
        int rn = grid.size();
        if(rn == 0) return 0;
        int rc = grid[0].size();
        if(rc == 0) return 0;

        int ans = 0;
        vector<vector<int>> dp(rc, vector<int>(rc, 0));
        for(int r = 0; r < rn; r++){
            for(int c1 = 0; c1 < rc; c1++){
                if(grid[r][c1] != 1) continue;
                
                for(int c2 = c1+1; c2 < rc; c2++){
                    if(grid[r][c2] == 1)
                    {
                        //find a new pair, firstly update answer
                        ans += dp[c1][c2];
                        dp[c1][c2]++;
                    }
                }
            }
        }
        return ans;
    }
};
