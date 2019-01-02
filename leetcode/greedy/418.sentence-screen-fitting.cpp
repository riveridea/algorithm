/*
 * @lc app=leetcode id=418 lang=cpp
 *
 * [418] Sentence Screen Fitting
 *
 * https://leetcode.com/problems/sentence-screen-fitting/description/
 *
 * algorithms
 * Medium (29.59%)
 * Total Accepted:    29.2K
 * Total Submissions: 98.8K
 * Testcase Example:  '["hello","world"]\n2\n8'
 *
 * Given a rows x cols screen and a sentence represented by a list of non-empty
 * words, find how many times the given sentence can be fitted on the screen.
 * 
 * 
 * Note:
 * 
 * A word cannot be split into two lines.
 * The order of words in the sentence must remain unchanged.
 * Two consecutive words in a line must be separated by a single space.
 * Total words in the sentence won't exceed 100.
 * Length of each word is greater than 0 and won't exceed 10.
 * 1 ≤ rows, cols ≤ 20,000.
 * 
 * 
 * 
 * 
 * Example 1: 
 * 
 * Input:
 * rows = 2, cols = 8, sentence = ["hello", "world"]
 * 
 * Output: 
 * 1
 * 
 * Explanation:
 * hello---
 * world---
 * 
 * The character '-' signifies an empty space on the screen.
 * 
 * 
 * 
 * 
 * Example 2: 
 * 
 * Input:
 * rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
 * 
 * Output: 
 * 2
 * 
 * Explanation:
 * a-bcd- 
 * e-a---
 * bcd-e-
 * 
 * The character '-' signifies an empty space on the screen.
 * 
 * 
 * 
 * 
 * Example 3: 
 * 
 * Input:
 * rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
 * 
 * Output: 
 * 1
 * 
 * Explanation:
 * I-had
 * apple
 * pie-I
 * had--
 * 
 * The character '-' signifies an empty space on the screen.
 * 
 * 
 */
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
	//greedy method,
	//we think about to expand rows to 
	
	//preprocessing the sentence
	string stc = "";
	for(auto s : sentence)
	{
	    stc += (s + " ");
	}
	int sln = stc.length();
	int start = 0;
	for(int i = 0; i < rows; i++)
	{
	    start += cols;  //trying fit the sentence to this row 
	    if(stc[start%sln] == ' ') //just hit the space, means we don't to trim any word
		start++;
	    else
	    {
		//go left to find a space 
		while(start > 0 && stc[(start - 1)%sln] != ' ')
		    start--;
	    }
	}

	return start/sln;
    }
};






























