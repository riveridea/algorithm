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
	vector<int> factors;		
	dfs(n, 2, {});
	return result;
    }

    void dfs(int n, int start, vector<int> factors)
    {
	for(int i = start; i <= sqrt(n); i++)  //try every first element less than sqrt(n)
	{
	    if(n%i == 0)
	    {
		vector<int> new_fact = factors;
		new_fact.push_back(i);
		dfs(n/i, i, new_fact); 
		new_fact.push_back(n/i); //n/i is not included yet
		result.push_back(new_fact);
	    }
	}
    }
};
































