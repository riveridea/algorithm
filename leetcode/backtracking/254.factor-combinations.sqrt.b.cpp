/*
 * [254] Factor Combinations
 *
 * https://leetcode.com/problems/factor-combinations/description/
 *
 * algorithms
 * Medium (43.67%)
 * Total Accepted:    47.1K
 * Total Submissions: 107.7K
 * Testcase Example:  '1'
 *
 * Numbers can be regarded as product of its factors. For example,
 * 
 * 
 * 8 = 2 x 2 x 2;
 * ⁠ = 2 x 4.
 * 
 * 
 * Write a function that takes an integer n and return all possible
 * combinations of its factors.
 * 
 * Note:
 * 
 * 
 * You may assume that n is always positive.
 * Factors should be greater than 1 and less than n.
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input: 1
 * Output: []
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input: 37
 * Output:[]
 * 
 * Example 3: 
 * 
 * 
 * Input: 12
 * Output:
 * [
 * ⁠ [2, 6],
 * ⁠ [2, 2, 3],
 * ⁠ [3, 4]
 * ]
 * 
 * Example 4: 
 * 
 * 
 * Input: 32
 * Output:
 * [
 * ⁠ [2, 16],
 * ⁠ [2, 2, 8],
 * ⁠ [2, 2, 2, 4],
 * ⁠ [2, 2, 2, 2, 2],
 * ⁠ [2, 4, 4],
 * ⁠ [4, 8]
 * ]
 * 
 * 
 */
class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> getFactors(int n) {
	//dfs and back tracking
	//optimization based on the fact that the first element of the combinations is alwasy less than the "current" sqrt(n)
	//this is another method of recusion, actualy decompose the for loop for i in start and sqrt(n)
	dfs(n, 2, {});
	return result;
    }

    void dfs(int n, int start, vector<int> factors)
    {
	if(start > sqrt(n)) return; //start as the first element 

	dfs(n, start+1, factors); //try the next start value with the same n
	if(n%start == 0)
	{
	    factors.push_back(start);
	    dfs(n/start, start, factors); 
	    factors.push_back(n/start); //n/i is not included yet
	    result.push_back(factors);
	}
    }
};
































