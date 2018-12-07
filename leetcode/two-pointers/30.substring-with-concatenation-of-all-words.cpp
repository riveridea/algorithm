/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (22.62%)
 * Total Accepted:    114K
 * Total Submissions: 504K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodstudentgoodword",
 * ⁠ words = ["word","student"]
 * Output: []
 * 
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
	//note the len of each word is identical
	//also, to detemine if we met a total concatenation, we need to make
	//sure we met the same number of the same word with the total number 
	//of the words, so we need two maps, one map as dictonary,
	//the other map, in the loop, to store the appearence of each word 
	//during each search of total number of words.
	vector<int> result;
	if(words.empty() || !s.size()) return result;
	unordered_map<string, int> dict;
	int wn = words.size(); //total number of words
	int m = s.size(); 
	int wl = words[0].size(); //word length
	//cout << wn << m << wl << endl;	


	//init the dictionary
	for(auto ss : words)
	{
	    dict[ss]++;
	}
	//search s fro each postion as candidated of concantenation, thus, i 
	//is less than m - wl*wn + 1
	for(int i = 0; i < m-wl*wn+1; i++)
	{
	    unordered_map<string, int> found; //count the found words
	    int j = 0; //j is number of words to be moved ahead
	    while(j < wn) //see if we can collect wn of valid words
	    {
		string word = s.substr(i+j*wl, wl);
	//	cout << word << "|";
		if(dict.find(word) != dict.end())
		{
		    found[word]++;
		    if(found[word] > dict[word]) break; // more than expected word found, not the answer
		}
		else
		{
		    break;
		}
		j++; //moving forward
	    }
	    if(j == wn) //we got an valid concatination	
	    {
		result.push_back(i); //start is i
	    }
	}
	return result;
    }
};
