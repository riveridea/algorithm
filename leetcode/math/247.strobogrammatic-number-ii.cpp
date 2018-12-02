/*
 * @lc app=leetcode id=247 lang=cpp
 *
 * [247] Strobogrammatic Number II
 *
 * https://leetcode.com/problems/strobogrammatic-number-ii/description/
 *
 * algorithms
 * Medium (42.63%)
 * Total Accepted:    38.9K
 * Total Submissions: 91.2K
 * Testcase Example:  '2'
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 * degrees (looked at upside down).
 * 
 * Find all strobogrammatic numbers that are of length = n.
 * 
 * Example:
 * 
 * 
 * Input:  n = 2
 * Output: ["11","69","88","96"]
 * 
 * 
 */
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
	//using recursive, start from n = 0, and n = 1
	//and every next solution will be based the put the preifx and 
	//appendix
	return helper(n, n); 
    }

private:
    vector<string> helper(int m, int n)
    {
	vector<string> res;
	if(m == 0) return vector<string>({""}); //don't output empty vector!!
	if(m == 1) 
	{
	    res.push_back("0");
	    res.push_back("1");
	    res.push_back("8");
	    return res;
	}
	
	//recursion
	vector<string> mid = helper(m-2, n);	
	for(int i = 0; i < mid.size(); i++)
	{
	    //for each mid, formuate all the possible current answers
	    if(m != n) res.push_back("0" + mid[i] + "0");
	    res.push_back("1" + mid[i] + "1");
	    res.push_back("6" + mid[i] + "9");
	    res.push_back("8" + mid[i] + "8");
	    res.push_back("9" + mid[i] + "6");
	}
	
	return res;
    }
};


















