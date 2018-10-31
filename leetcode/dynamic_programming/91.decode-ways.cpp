/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.14%)
 * Total Accepted:    208.9K
 * Total Submissions: 988K
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
	//this is vairant of climing ladders
	//everytime you either move 1 step or move 2 steps
	//f[n] represents the maximum ways of decoding to reach step n, but not including n yet
	//we can reach f[n] from n-1 or n-2,
	//thus f[n] = f[n-1] + f[n-2] 
	//using rolling array, like cur = cur + pre;
	//the difference is sometimes for the s[i-1] == '0' or s[i-2][i-1] > "2,6"
	//we can say we never reach this f[i-1] or f[i-2], thus cur = 0, pre = 0
	if(s.length() == 0 || s[0] == '0' ) return 0;

	int pre = 0; //f[i-2]
	int cur = 1; //f[i-1]
	for(int i = 1; i <= s.length(); i++) 
	{
	    if (s[i-1] ==  '0') cur = 0;
	    if (i < 2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) pre = 0;

	    int temp = cur;
	    cur = cur + pre;
	    pre = temp;

	    cout << "f[" << i << "], " << "cur = " << cur << endl;
	}
        return cur; //f[n] represents the final result, n = s.length, means we finished all n chars and reached the end after s[n-1]
    }
};
