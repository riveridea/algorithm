/*
 * [291] Word Pattern II
 *
 * https://leetcode.com/problems/word-pattern-ii/description/
 *
 * algorithms
 * Hard (42.08%)
 * Total Accepted:    37.8K
 * Total Submissions: 89.8K
 * Testcase Example:  '"abab"\n"redblueredblue"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty substring in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abab", str = "redblueredblue"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
 * Output: true
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aabb", str = "xyzabcxzyabc"
 * Output: false
 * 
 * 
 * Notes:
 * You may assume both pattern and str contains only lowercase letters.
 * 
 */
class Solution {
public:
	unordered_map<char, string> ps_map;
	unordered_set<string> pset; 
    bool wordPatternMatch(string pattern, string str) {
		//this problem is solved by brutal force with backtracking
		//start from the ith of the str and try every possible
		// substring started at i as candidated j pattern 
		// we have two cases
		// 1. the j pattern has been detected, then test of the corresponding
		// pattern is the start of current str[i...], if no, return false
		// if yes, go ahead with dfs
		// 2. the j pattern has not been detecedt
		// then try dfs for every sub str[i...k], k < str.size();
		//dfs succeeds then we find true
		//otherwise try next k, but with backtracking
		//a map is used to store the pattern char -> substr
		//a set is used to store if the pattern substr is already detected(no need to dfs)
		
		return dfs(0, 0, pattern, str);
    }

	bool dfs(int i, int j, string& pattern, string& str){
		//stop cases:
		if(i == str.size() && j == pattern.size()) 
			return true;
		if(i == str.size() || j == pattern.size())
			return false;

		char pat_char = pattern[j];

		//check if this pattern substring has been determined
		//case 1. the pattern string is already seen
		if(ps_map.find(pat_char) != ps_map.end()){
			//check if the str[i...] starts with the pattern string
			string ps = ps_map[pat_char];
			if((str.substr(i)).rfind(ps, 0) == 0){
				//do dfs for next pattern with next chunk of str
				return dfs(i+ps.size(), j+1, pattern, str);
			}
			return false; // this dfs path is not correct
		}
		
		//case 2. the pattern has not been explored
		for(int k = i; k < str.size(); k++){
			//this substring as candidated pattern to be explored
			string cs = str.substr(i, k-i+1);
			//avoid duplicated, because at this time we assume pat_char has not mapped yet
			//if it is already in the pset it means other pattern string is already using 
			//this character, so we should drop this candidate to aovid two substring mapped
			//to the same pattern char!!
			if(pset.find(cs) != pset.end()) continue;

			//prepare dfs, store the current status
			ps_map[pattern[j]] = cs;
			pset.insert(cs);
			if(dfs(k+1, j+1, pattern, str) == true) return true; // this path works!
			//backtracking as this path won's work
			ps_map.erase(pattern[j]);
			pset.erase(cs);
		}
		return false; //we've tried but no luck
	}
};
