/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.43%)
 * Total Accepted:    236.6K
 * Total Submissions: 615.6K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
		//bijection mapping
		//directly mapping the char in s to t, check 
		//but need to avoid duplicated mapping, which means
		//two distinct char in s mapped to the same char in t
		//so 1 map and 1 set is used 
		//map is used to map from s to t
		//set is to store the char already been mapped from s
		if(s.size() != t.size()) return false;

		unordered_map<char, char> m;
		unordered_set<char> st;
		for(int i = 0; i < s.size(); i++){
			if(m.find(s[i]) != m.end()){
				if(t[i] != m[s[i]]) return false;
			}
			else{
				if(st.find(t[i]) != st.end()) return false;
				m[s[i]] = t[i];
				st.insert(t[i]);
			}
		}
		return true;
    }
};
