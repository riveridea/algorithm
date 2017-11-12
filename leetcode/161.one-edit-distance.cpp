/*
 * [161] One Edit Distance
 *
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
