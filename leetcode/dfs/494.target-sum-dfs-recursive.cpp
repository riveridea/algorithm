/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.29%)
 * Total Accepted:    73.9K
 * Total Submissions: 166.8K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
class Solution {
    int size;
public:
    int findTargetSumWays(vector<int>& nums, int S) {
	//try the DFS, in recursive way
	//for each number the next has two possible ways
	//each way go to the leaf will determine if sum 
	size = nums.size();
	vector<int> sums(size, 0);
	sums[size-1] = nums[size-1];
	for(int i = size-2; i >= 0; i--)
	{
	    sums[i] = nums[i] + sums[i+1];
	}
	return helper(nums, sums, S, 0, 0);
    }

    int helper(vector<int>& nums, vector<int>& sums,  int S, int curr_sum, int index)
    {
	if(index == size)
	    return S == curr_sum ? 1 : 0;

	if(sums[index] < abs(S - curr_sum)) return 0; 
	return helper(nums, sums,  S, curr_sum+nums[index], index+1) +
	       helper(nums, sums,  S, curr_sum-nums[index], index+1);
    }
};
















