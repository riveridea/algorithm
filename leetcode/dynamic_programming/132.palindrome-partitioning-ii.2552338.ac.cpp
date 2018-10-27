/*
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (25.90%)
 * Total Accepted:    90.6K
 * Total Submissions: 349.7K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */
class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        
        int f[n+1]; //0-n
        for(int i=0; i<=n;i++){
            f[i] = n-1-i; //the maximum cuts is cut every single character
        }
        bool b[n][n];
        fill_n(&b[0][0], n*n, false);
        
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                //fir determine if [i j] is palindrome
                if ((s[i] == s[j])  && (j - i < 2 || b[i+1][j-1])){
                    b[i][j] = true;
                    f[i] = min(f[i], f[j+1]+1); //f[n] could be accessed
                }
            }
        }
        
        return f[0];
    }
};
