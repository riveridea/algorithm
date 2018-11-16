/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (40.41%)
 * Total Accepted:    250.6K
 * Total Submissions: 620.2K
 * Testcase Example:  '[1,2,3,1]'
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
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */
class Solution {
public:
    int rob(vector<int>& nums) {
	//f[i] = max(f[i-1], f[i-2]+nums[i])        
	if(nums.size() == 0) return 0;
	
	int pre = 0; //f[i-2]
	int cur = 0; //f[i-1]
	int n = nums.size();
	for(int i = 0; i < n; i++)
	{
	    int temp = cur;
	    cur = max(cur, pre+nums[i]);
	    pre = temp;
	}
	return cur;
    }
};
