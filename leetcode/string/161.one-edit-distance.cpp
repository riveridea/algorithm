/*
 * [161] One Edit Distance
 *
<<<<<<< HEAD
 * https://leetcode.com/problems/one-edit-distance/description/
 *
 * algorithms
 * Medium (31.26%)
 * Total Accepted:    63.4K
 * Total Submissions: 202.9K
 * Testcase Example:  '"ab"\n"acb"'
 *
 * Given two strings s and t, determine if they are both one edit distance
 * apart.
 * 
 * Note: 
 * 
 * There are 3 possiblities to satisify one edit distance apart:
 * 
 * 
 * Insert a character into s to get t
 * Delete a character from s to get t
 * Replace a character of s to get t
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ab", t = "acb"
 * Output: true
 * Explanation: We can insert 'c' into s to get t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cab", t = "ad"
 * Output: false
 * Explanation: We cannot get t from s by only one step.
 * 
 * Example 3:
 * 
 * 
 * Input: s = "1203", t = "1213"
 * Output: true
 * Explanation: We can replace '0' with '1' to get t.
 * 
=======
 * https://leetcode.com/problems/one-edit-distance
 *
 * algorithms
 * Medium (31.57%)
 * Total Accepted:    41.9K
 * Total Submissions: 132.6K
 * Testcase Example:  '""\n""'
 *
 * Given two strings S and T, determine if they are both one edit distance
 * apart.
>>>>>>> e7e84f1dfcdb2d9ea90c777dd24b0345534f206c
 */
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
	int m = s.size();
	int n = t.size();

	if(abs(m-n) > 1) return false;

	// m = n or |m - n| = 1
	int edits = 0;
	int is = 0, it = 0; //index for two strings
	while(is < m && it < n) //unitl any end of the strings	
	{
	    if(s[is] != t[it]) 
	    {
		if(edits == 1) return false;	
		edits++;
		if(m > n) 
		    is++;
		else if(m < n)
		    it++;
		else
		{
		    is++;
		    it++;
		}
	    }
	    else
	    {
		is++;
		it++;
	    }
	}

	//dont forget |m - n| = 1
	if(is < m || it < n) edits++; //if the extra character exist in any string
	cout << edits << endl;
	return edits == 1;
    }
};
