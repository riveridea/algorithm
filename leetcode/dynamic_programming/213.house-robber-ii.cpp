/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (34.70%)
 * Total Accepted:    93.7K
 * Total Submissions: 270K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */
class Solution {
public:
    int rob(vector<int>& nums) {
	//actually this problem can be solved by DP twice, between 0 and n-1, or between 1 and n        
	if (nums.size() == 1) return nums[0];
	return max(rob_sub(nums, 0, nums.size()-1), rob_sub(nums, 1, nums.size()));
    }
private:
    int rob_sub(vector<int>& nums, int start, int end)
    {
	int pre = 0; 
	int cur = 0;
	for(int i = start; i < end; i++)
	{
	    int temp = cur;
	    cur = max(cur, pre + nums[i]);
	    pre = temp;
	}
	return cur;
    }
};
