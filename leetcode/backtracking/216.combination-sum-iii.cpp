/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (48.95%)
 * Total Accepted:    102.1K
 * Total Submissions: 208.6K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
	//dfs and branch cut 
	//each time return to the current level, remove the last one
	vector<vector<int>> result;
	vector<int> path;
	dfs(k, n, path, result);

	return result;
    }
private:
    void dfs(int level, int gap, vector<int> &path, vector<vector<int>> &result)
    {
	//if reaching the last level, need to check if answer is found
	if (level == 0 )
	{
	    if(gap == 0)  // <--- Anwser
	    {
		//got the answer
		result.push_back(path);
	    }
	     
            return; // <---- No anwser
	}

	if (gap < 1) return; // in case skip the sum n
	//dfs now
	//should start from last path node + 1
	int start = path.empty() ? 1 : path.back() + 1;
	for(int i = start; i <= 9; i++)
	{
	    path.push_back(i);
	    //search the next level
	    dfs(level - 1, gap - i, path, result);
	    //return the current level, remove the curent node and try the other one in the next iteration
	    path.pop_back();
	}
    }
};
