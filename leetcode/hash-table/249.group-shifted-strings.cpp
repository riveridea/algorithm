/*
 * @lc app=leetcode id=249 lang=cpp
 *
 * [249] Group Shifted Strings
 *
 * https://leetcode.com/problems/group-shifted-strings/description/
 *
 * algorithms
 * Medium (46.91%)
 * Total Accepted:    43.1K
 * Total Submissions: 91.9K
 * Testcase Example:  '["abc","bcd","acef","xyz","az","ba","a","z"]'
 *
 * Given a string, we can "shift" each of its letter to its successive letter,
 * for example: "abc" -> "bcd". We can keep "shifting" which forms the
 * sequence:
 * 
 * 
 * "abc" -> "bcd" -> ... -> "xyz"
 * 
 * Given a list of strings which contains only lowercase alphabets, group all
 * strings that belong to the same shifting sequence.
 * 
 * Example:
 * 
 * 
 * Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 * Output: 
 * [
 * ⁠ ["abc","bcd","xyz"],
 * ⁠ ["az","ba"],
 * ⁠ ["acef"],
 * ⁠ ["a","z"]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
	//use the diff between adjacent char to identify the strings belong to the same group        
	unordered_map<string, vector<string>> ma;
	//update the ma, base on the same shift diffs key
	for(auto s : strings)
	{
	    ma[shift(s)].push_back(s); 
	}
	vector<vector<string>> groups;
	for(auto m : ma)
	{
	    vector<string> group = m.second;
	    sort(group.begin(), group.end());
	    groups.push_back(group);
	}
	return groups;
    }
private:
    string shift(string s)
    {
	string sh;
	for(int i = 1; i < s.size(); i++)
	{
	    int diff = s[i] - s[i-1];
	    if(diff < 0) diff += 26;
	    sh += 'a' + diff + ',';
	}
	return sh;
    }
};
