/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (43.60%)
 * Total Accepted:    74.7K
 * Total Submissions: 171.3K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * ⁠Given an integer array with all positive numbers and no duplicates, find
 * the number of possible combinations that add up to a positive integer
 * target.
 * 
 * Example:
 * 
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * 
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers? 
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
	// this is DP problme
	// define the dp[i] as the possible combination count to sum to target value i, where i is less 
	// and equal to target
	// for each i, we will try every candidates in nums, meaning to update dp[i] based on 
	// the existing dp[i - num] if num is no greater than i, until we get dp[target] which is the final answer
	vector<int> dp(target + 1);
	dp[0] = 1; // at least one 0 
	sort(nums.begin(), nums.end()); //how about no sort?
	for (int i = 1; i <= target; i++)
	{
	    for(auto num : nums)
	    {
		//if(i < num) continue; // if don't sort nums firstly, you need try every num 
		if(i < num) break;  
		dp[i] += dp[i - num];
	    }
	}
	return dp[target];
    }
};
