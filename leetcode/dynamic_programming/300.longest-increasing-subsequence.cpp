/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (39.39%)
 * Total Accepted:    163.9K
 * Total Submissions: 416K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
	//Dynamic programming
	//f[i] represents the solution of the array ending with i (including i)
	//for a j > i, if nums[j] > nums[i], then f[i] must be the prefix of f[j]
	//the optimization would be find the optimal solution from every possible 
	//prefix
	
	if(nums.size() == 0) return 0;

	vector<int> f(nums.size(), 1);
	int global = 1;
	for(int j = 1; j < nums.size(); j++)
	{
	    //find the f[j] based all possible prefix f[i]
	    for(int i = 0; i < j; i++)
	    {
		if(nums[i] < nums[j])
		    f[j] = max(f[j], f[i] + 1);
	    }
	    //udpate global for each j
	    global = max(global, f[j]);
	}

	return global;
    }
};
