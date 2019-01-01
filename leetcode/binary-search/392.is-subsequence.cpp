/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Medium (45.70%)
 * Total Accepted:    73.3K
 * Total Submissions: 160.4K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 
 * Given a string s and a string t, check if s is subsequence of t.
 * 
 * 
 * 
 * You may assume that there is only lower case English letters in both s and
 * t. t is potentially a very long (length ~= 500,000) string, and s is a short
 * string (
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * 
 * Example 1:
 * s = "abc", t = "ahbgdc"
 * 
 * 
 * Return true.
 * 
 * 
 * Example 2:
 * s = "axc", t = "ahbgdc"
 * 
 * 
 * Return false.
 * 
 * 
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
	//this is follow up as the number of s is quite big. 
	//a map is considered to store each character and its asscociated posistion in t
	//when checking the s, make sure the 
	//the character is in the map and 
	//the character can ocurr in the position equal or greater than the next of its preivous 
	//character in s
	//a binary search is used to search if the new character can be in the position list
	//if(!s.size() || !t.size()) return false;
	unordered_map<char, vector<int>> pmap; //positions map for each character in t

	//preprocessing of the t
	for(int i = 0; i < t.size(); i++)
	{
	    pmap[t[i]].push_back(i);
	}

	int new_idx = -1; //each  time we need to know the next start after a character is hit 
	for(int i = 0; i < s.size(); i++)
	{
	    char c = s[i];
	    if(pmap.find(c) == pmap.end())
		return false;
	    else
	    {
		//cout << s[i] << ":";
		new_idx = bsearch(new_idx, pmap[c], 0, pmap[c].size() - 1);
		cout << new_idx;
		if(new_idx == -1)
		    return false;

		new_idx++;
	    }
	}
	return true;
    }

    //find the first element equal or greater than the idx provided
    int bsearch(int idx, vector<int>& list, int start, int end)
    {
	int recordend = end;
	while(start <= end)
	{
	    int mid = start + (end - start)/2;
	    if(list[mid] < idx)
		start = mid + 1;  //start will stop at the place where first equal or greater, if any
	    else
		end = mid - 1;
	}
	return start == recordend+1 ? -1 : list[start]; //if no, start would try everything until out of boundary
    }
};


















