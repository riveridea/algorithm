/*
 * [320] Generalized Abbreviation
 *
 * https://leetcode.com/problems/generalized-abbreviation/description/
 *
 * algorithms
 * Medium (47.18%)
 * Total Accepted:    33.1K
 * Total Submissions: 70.2K
 * Testcase Example:  '"word"'
 *
 * Write a function to generate the generalized abbreviations of a word. 
 * 
 * Note: The order of the output does not matter.
 * 
 * Example:
 * 
 * 
 * Input: "word"
 * Output:
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
 * "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
	//using dfs based backtracking
	vector<string> result;

	result.push_back(word);
	dfs(0, word, result);

	return result;
    }

private:
    void dfs(int start, string base, vector<string> &result)
    {
	//the dfs exhaust all possible next states
	//all possible starts
	//all possible substrings between start and end, determined by different nums 


	if(start >= base.length())
	{
	    return; 
	}

	//from start to end, exhausting all the next state
	for(int i = start; i < base.length(); i++)
	{
	    //for each start, dfs the next substring with prefix of number
	    for(int j = 1; i + j <= base.length(); j++)
	    {
		string num = to_string(j);  // this is the num to replace the characters
		string answer = base.substr(0, i) + num + base.substr(i + j);
		result.push_back(answer);
		//explore the substring 
	        dfs(i + 1 + num.length(), answer, result);	
	    } 

	}
    
    }
};
