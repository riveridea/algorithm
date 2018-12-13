/*
 * @lc app=leetcode id=186 lang=cpp
 *
 * [186] Reverse Words in a String II
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
 *
 * algorithms
 * Medium (34.63%)
 * Total Accepted:    55K
 * Total Submissions: 158.7K
 * Testcase Example:  '["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]'
 *
 * Given an input string , reverse the string word by word. 
 * 
 * Example:
 * 
 * 
 * Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 * 
 * Note: 
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces.
 * The words are always separated by a single space.
 * 
 * 
 * Follow up: Could you do it in-place without allocating extra space?
 * 
 */
class Solution {
public:
    void reverseWords(vector<char>& str) {
	//reverse the whole string firstly 
	//and reverse the each word
	reverse(str.begin(), str.end());
	//reverse each word
	int j = 0;
	for(int i=0; i < str.size(); i = j+1)
	{
	    for(j=i; j < str.size() && str[j] != ' '; j++); //find the position of " "
	    reverse(str.begin()+i, str.begin()+j);
	}
    }

};
