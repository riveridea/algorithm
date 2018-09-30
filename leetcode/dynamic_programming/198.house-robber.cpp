/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber
 *
 * algorithms
 * Easy (39.44%)
 * Total Accepted:    166.8K
 * Total Submissions: 422.9K
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
	//bottom up DP
	//pre - (i-2) optimal solution
	//cur - (i-1) optimal solution
	//compare pre + nums[i] and cur to get (i) optimal solution
	int n = nums.size(), pre = 0, cur = 0;
	for (int i = 0; i < n; i++)
	{
	    int temp = max(pre + nums[i], cur); //cur here is i-1 solution, pre is i-2 solution
	    pre = cur;  //updated to (i-1) solution
	    cur = temp; //updated to (i) solution
	}

	return cur;
    }
};
