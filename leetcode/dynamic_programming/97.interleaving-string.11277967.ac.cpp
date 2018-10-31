/*
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (26.27%)
 * Total Accepted:    94.6K
 * Total Submissions: 360.2K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        
        vector<bool> f(s2.length()+1, true); //
        
        //initialization the boundary suppose s1 is zero length
        for(int i = 1; i<= s2.length(); i++){
            f[i] = s2[i-1] == s3[i-1] && f[i-1];
        }
        
        //start update sliding array every i
        for(int i = 1; i<=s1.length(); i++){
            //init f[0] as j = 0 as start point
            f[0] = s1[i-1] == s3[i-1] && f[0];
            
            for(int j = 1; j<=s2.length(); j++){
                f[j] = (s1[i-1] == s3[i+j-1] && f[j]) 
                     ||(s2[j-1] == s3[i+j-1] && f[j-1]);
            }
        }
        
        return f[s2.length()];
    }
};
