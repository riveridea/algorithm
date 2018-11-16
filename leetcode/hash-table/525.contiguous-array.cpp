/*
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (42.10%)
 * Total Accepted:    32.8K
 * Total Submissions: 78K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1. 
 * 
 * 
 * Example 1:
 * 
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 * 
 * 
 * 
 * Note:
 * The length of the given binary array will not exceed 50,000.
 * 
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
	//hash table 
	//this is same as 325 maximum size subarray sum equals k
	//the difference is that 0 shouuld be -1 and k should be 0
	//when equals number 0(-1) and 1, means sum is 0
	if(nums.empty()) return 0;

	unordered_map<int, int> sums;
	int n = nums.size();
	int curr_sum = 0;
	int max_len = 0;

	for(int i = 0; i < n; i++)
	{
	    curr_sum += (nums[i] == 0? -1: 1);
	    if(curr_sum == 0)
	    {
		max_len = i + 1;
	    }
	    else if(sums.find(curr_sum) != sums.end())
	    {
		max_len = max(max_len, i - sums[curr_sum]);
	    }

	    if(sums.find(curr_sum) == sums.end())
	    {
		sums[curr_sum] = i;
	    }
	}

	return max_len;
    }
};
