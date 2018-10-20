/*
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (38.97%)
 * Total Accepted:    135.8K
 * Total Submissions: 348.6K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
class Solution {
public:
    int numSquares(int n) {
        //dynamic programming
        // if f(m) is the least squares number, and if we already know f(1）to f(m-1)
        // then we can use dynamic programming to find minimum squares number, just try every square 
        //less than m get the minimum number = min(f(m - i*i) +1, curr_squres)
        
        static vector<int> minNums {0};
        while(minNums.size() <= n){
            int curr_squares = INT_MAX;
            int curr_num = minNums.size();
            //dp to update the f(m)
            for(int i = 1; i*i <= curr_num; i++){
                curr_squares = min(curr_squares, minNums[curr_num - i*i]+1);
            }
            //get the minimum numbers
            minNums.push_back(curr_squares);
        }
        return minNums[n];
    }
};
