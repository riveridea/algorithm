/*
 * @lc app=leetcode id=616 lang=cpp
 *
 * [616] Add Bold Tag in String
 *
 * https://leetcode.com/problems/add-bold-tag-in-string/description/
 *
 * algorithms
 * Medium (39.90%)
 * Total Accepted:    25.9K
 * Total Submissions: 64.9K
 * Testcase Example:  '"abcxyz123"\n["abc","123"]'
 *
 * Given a string s and a list of strings dict, you need to add a closed pair
 * of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If
 * two such substrings overlap, you need to wrap them together by only one pair
 * of closed bold tag. Also, if two substrings wrapped by bold tags are
 * consecutive, you need to combine them. 
 * 
 * Example 1:
 * 
 * Input: 
 * s = "abcxyz123"
 * dict = ["abc","123"]
 * Output:
 * "<b>abc</b>xyz<b>123</b>"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * s = "aaabbcc"
 * dict = ["aaa","aab","bc"]
 * Output:
 * "<b>aaabbc</b>c"
 * 
 * 
 * 
 * Note:
 * 
 * The given dict won't contain duplicates, and its length won't exceed 100.
 * All the strings in input have length in range [1, 1000]. 
 * 
 * 
 */
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
	//let's do someting different to the hashing
	//use a bool array to make each character bold if it is in a word of dict
	//after that, the post-process would return a result.
	int n = s.size();
	vector<bool> mask(n, false);
	//check each start
	for(int i = 0; i < n; i++)
	{
	    string prefix = s.substr(i);
	    //compare for each word in dictionary
	    for(string word: dict)
	    {
		if(prefix.rfind(word, 0) == 0) 
		    for(int j = i; j < word.size() + i; j++) 
			mask[j] = true;
	    }
	}

	//post process
	string ans;
	for(int i = 0; i < n; i++)
	{
	    if((mask[i] == true) && (i==0 || mask[i-1] == false))	    
		ans.append("<b>");
	    ans.append(&s[i], 1);

	    if((mask[i] == true) && (i==n-1 || mask[i+1] == false))
		ans.append("</b>");
	}
	return ans;
    }
};
