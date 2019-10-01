/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (31.73%)
 * Total Accepted:    80.1K
 * Total Submissions: 250.9K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, find all pairs of distinct indices (i, j) in
 * the given list, so that the concatenation of the two words, i.e. words[i] +
 * words[j] is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]] 
 * Explanation: The palindromes are
 * ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]] 
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
	//use a map to store the cadidates
	//each candidate is a reversed string of the element of string array
	//1. reverse string and construct the map
	//2. edge case, for empty string, all the palindrome string is the solution
	//3. now iterate each string in the original array
	//   we partition the string to two part (left + right) 
	//   now with the help of the map, we search the solution for two scenarios:
	//   a) left + right + candidate, if left == candidate and right is palindrome
	//   b) candidate + left + right, if right == candidate, and left is palindrome

	vector<vector<int>> ans;
	//1. reverse the string and construct the map
	unordered_map<string, int> dict;
	for(int i = 0; i < words.size(); i++){
	    string w = words[i];
	    reverse(w.begin(), w.end());
	    dict.insert({w, i});
	}

	//2. edge case
	if(dict.find("") != dict.end()){
	    int x = dict[""];
	    for(int i = 0; i < words.size(); i++){
		if(i == x) continue;
		if(isPalindrome(words[i])) ans.push_back({x, i});
	    }
	}

	//3. brutle force to check left + right and candidate
	for(int i = 0; i < words.size(); i++){
	    for(int j = 0; j < words[i].size(); j++){
		string left = words[i].substr(0, j);
		string right = words[i].substr(j);

		//check left + right + cadidate
		if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i){
		    ans.push_back({i, dict[left]});
		}
	
		//check candiate + left + right
		if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i){
		    ans.push_back({dict[right], i});
		}
	    }
	}

	return ans;

    }

    bool isPalindrome(string s){
	int i = 0; 
	int j = s.size() - 1;
	while(i < j){
	    if(s[i++] != s[j--]) return false;
	}
	return true;
    }
};
