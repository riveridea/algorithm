/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (40.77%)
 * Total Accepted:    35.9K
 * Total Submissions: 88K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * 
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 * 
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * 
 * Note:
 * 
 * 
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * 
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * 
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 * 
 * 
 * 
 * 
 */
typedef vector<int> v1d;
typedef vector<v1d> v2d;
typedef vector<v2d> v3d;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //this is a knapsack problem with 2D weights
        //we firstly use 3D dp to solve it then convert it to 
        //2D, during 2D conversion, need to pay attention only
        //bottom up is valid

        //dp[i][j][k] is defined as when we looking at the ith 
        //string, and the available 0s is j and 1s is k,
        //how many maximum string number would be, if
        //a. this string is picked
        //b. this string is not picked
        //dp[i][j][k] = max(1 + dp[i-1][j-zeros][k-ones], dp[i-1][j][k])
        //and also don't forget if zeros and ones are smaller than
        //
        int l = strs.size();
        if(!l) return 0;


/* 3D solution
        //dp memo
        v3d dp(l+1, v2d(m+1, v1d(n+1,0)));
        //start dp
        for(int i = 1; i <= l; i++){
            string s = strs[i-1];
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.length() - ones;
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(j >= zeros && k >= ones)
                        dp[i][j][k] = max(1+dp[i-1][j-zeros][k-ones],
                                     dp[i-1][j][k]);
                    else
                        dp[i][j][k] = dp[i-1][j][k]; 
                }
            }
        }
        return dp[l][m][n];
*/

//2D solution
        //dp memo
        v2d dp(m+1, v1d(n+1,0));
        //start dp
        for(int i = 1; i <= l; i++){
            string s = strs[i-1];
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.length() - ones;
            for(int j = m; j >= zeros; j--){
                for(int k = n; k >= ones; k--){
                    //if(j >= zeros && k >= ones)
                        dp[j][k] = max(1+dp[j-zeros][k-ones],
                                     dp[j][k]);
                    /*
                    else
                        dp[j][k] = dp[j][k];  //last iteration
                    */
                }
            }
        }
        return dp[m][n];
    }
};
