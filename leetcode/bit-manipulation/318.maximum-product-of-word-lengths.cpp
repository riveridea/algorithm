/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (47.06%)
 * Total Accepted:    71.7K
 * Total Submissions: 152.4K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, find the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. You may
 * assume that each word will contain only lower case letters. If no such two
 * words exist, return 0.
 * 
 * Example 1:
 * 
 * 
 * Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16 
 * Explanation: The two words can be "abcw", "xtfn".
 * 
 * Example 2:
 * 
 * 
 * Input: ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4 
 * Explanation: The two words can be "ab", "cd".
 * 
 * Example 3:
 * 
 * 
 * Input: ["a","aa","aaa","aaaa"]
 * Output: 0 
 * Explanation: No such pair of words.
 * 
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
	//the idea to represent the presence of the characters of the word
	//is to use bit mask of a 32bit number
	unordered_map<int, int> maskLen; //store the max len of words with the same combinations of character

	int result = 0;
	for(string w : words)
	{
	    int mask = 0;
	    for(auto c : w)
	    {
		mask |= 1 << (c - 'a');
	    }
	    
	    maskLen[mask] = max(maskLen[mask], (int)w.size());
	    
	    //update the result
	    for(auto ml : maskLen)
	    {
		if(!(mask & ml.first))
		{
		    result = max(result,  maskLen[mask]*ml.second);
		}
	    }
	}
	return result;
    }
};
