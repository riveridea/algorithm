/*
 * @lc app=leetcode id=288 lang=cpp
 *
 * [288] Unique Word Abbreviation
 *
 * https://leetcode.com/problems/unique-word-abbreviation/description/
 *
 * algorithms
 * Medium (19.11%)
 * Total Accepted:    37.7K
 * Total Submissions: 197.5K
 * Testcase Example:  '["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]\n[[["deer","door","cake","card"]],["dear"],["cart"],["cane"],["make"]]'
 *
 * An abbreviation of a word follows the form <first letter><number><last
 * letter>. Below are some examples of word abbreviations:
 * 
 * 
 * a) it                      --> it    (no abbreviation)
 * 
 * ⁠    1
 * ⁠    ↓
 * b) d|o|g                   --> d1g
 * 
 * ⁠             1    1  1
 * ⁠    1---5----0----5--8
 * ⁠    ↓   ↓    ↓    ↓  ↓    
 * c) i|nternationalizatio|n  --> i18n
 * 
 * ⁠             1
 * ⁠    1---5----0
 * ↓   ↓    ↓
 * d) l|ocalizatio|n          --> l10n
 * 
 * 
 * Assume you have a dictionary and given a word, find whether its abbreviation
 * is unique in the dictionary. A word's abbreviation is unique if no other
 * word from the dictionary has the same abbreviation.
 * 
 * Example:
 * 
 * 
 * Given dictionary = [ "deer", "door", "cake", "card" ]
 * 
 * isUnique("dear") -> false
 * isUnique("cart") -> true
 * isUnique("cane") -> false
 * isUnique("make") -> true
 * 
 * 
 */
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
	for(auto s : dictionary)	 
	{
	    int n = s.size();
	    string abbr = s[0] + to_string(s.size()) + s[n-1];
	    mp[abbr].insert(s);
	}
    }
    
    bool isUnique(string word) {
	int n = word.size();
	string abbr = word[0] + to_string(word.size()) + word[n-1];
	return mp[abbr].count(word) == mp[abbr].size();
    }
private:
    //map<string, int> is not working, becuase you need to cover the case lie
    //the testing string is the same as the one in the dictionary, in which the return value 
    //shoule be true, mean unique
    unordered_map<string, unordered_set<string>> mp;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
