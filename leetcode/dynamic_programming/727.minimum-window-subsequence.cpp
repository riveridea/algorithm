/*
 * @lc app=leetcode id=727 lang=cpp
 *
 * [727] Minimum Window Subsequence
 *
 * https://leetcode.com/problems/minimum-window-subsequence/description/
 *
 * algorithms
 * Hard (38.67%)
 * Total Accepted:    19.5K
 * Total Submissions: 50.5K
 * Testcase Example:  '"abcdebdde"\n"bde"'
 *
 * Given strings S and T, find the minimum (contiguous) substring W of S, so
 * that T is a subsequence of W.
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "". If there are multiple such minimum-length windows, return
 * the one with the left-most starting index.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * S = "abcdebdde", T = "bde"
 * Output: "bcde"
 * Explanation: 
 * "bcde" is the answer because it occurs before "bdde" which has the same
 * length.
 * "deb" is not a smaller window because the elements of T in the window must
 * occur in order.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All the strings in the input will only contain lowercase letters.
 * The length of S will be in the range [1, 20000].
 * The length of T will be in the range [1, 100].
 * 
 * 
 * 
 */
class Solution {
public:
    string minWindow(string S, string T) {
        //dynamic programming,
        //dp[j][e] = s;
        //is defined as for S[0...e] and T[0...j], we have the answer S[s...e]
        //or -1 if no answer
        //thus the final answer would be
        //for i = 0 t s.length()-1, find in dp[T.length -1][i] to get the minimu i - s
       
        //though we could use a 2D dp, but dp[j][e] only depends on dp[j-1][e'], thus
        //it can be solved by rolling array, dp[2][s.size()]
        int n = S.size(), m = T.size();
        if(n == 0 || m == 0) return "";

        vector<vector<int>> dp(2, vector<int>(n, -1));
        //for T[0], we udpate dp[0][e] for each s[0...e]
        for(int i = 0; i < n; ++i){
            dp[0][i] = (S[i] == T[0])?i:-1;
        }
        
        //check each T[0..j]
        for(int j = 1; j < m; ++j){
            int last = -1; // cache the last j's answer
            //clear this round of dp
            fill(dp[j&1].begin(), dp[j&1].end(), -1);
            for(int i = 0; i < n; ++i){
                //update dp[j][i] with last
                if(last >= 0 && S[i] == T[j]) //it means the solutin can be reused
                    dp[j&1][i] = last;
                //update the last for next usage, always the latest (s,e) is used 
                if(dp[~j&1][i] >= 0)
                    last = dp[~j&1][i];
            }
        }

        //find the answer
        int start = 0, end = n;
        for(int e = 0; e < n; ++e){
            int s = dp[(m-1)&1][e];
            //update the end and start
            if(s >= 0 && e - s < end - start){
                end = e;
                start = s;
            }
        }
        return end < n ? S.substr(start, end-start+1):"";
   }
};
