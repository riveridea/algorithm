/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (35.75%)
 * Total Accepted:    158.8K
 * Total Submissions: 444K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
		if(pattern.size() == 0) return false;
		if(str.size() == 0) return false;

		char pstr[str.size() + 1];
		strcpy(pstr, str.c_str());
		vector<string> ps;
		char* token = strtok(pstr, " ");
		while(token != NULL){
			ps.push_back(string(token));
			token = strtok(NULL, " ");	
		}
		
		unordered_map<string, char> m;
		unordered_map<char, char> mp;
		char p = 'a';
		string encoded_p;
		for(auto s: ps){
			if(m.find(s) == m.end()){
				encoded_p += p;
				m[s] = p++;
			}
			else{
				encoded_p += m[s];
			}
		}
	
		string cpat;
		p = 'a';
		for(auto c: pattern){
			if(mp.find(c) == mp.end()){
				cpat += p;
				mp[c] = p++; 
			}
			else{
				cpat += mp[c];
			}
		}
			
		return !cpat.compare(encoded_p);
    }
};

