/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (33.17%)
 * Total Accepted:    217.7K
 * Total Submissions: 656.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
	int n = nums.size();
	if (n < 3) return 0;

	//must sort firstly
	int c = nums[0] + nums[1] + nums[2]; //must start with a valid value
	sort(nums.begin(), nums.end());
	for(int i = 0; i < n - 2; i++)
	{
	    int left = i + 1; 
	    int right = n -1;
	    while(left < right)
	    {
		int currSum = nums[i] + nums[left] + nums[right];
		//see if closest can be updated
		if (currSum == target) return currSum;
		if(abs(currSum - target) < abs(target - c))
		    c = currSum;

		//update the left and right
		if(currSum > target)
		{
		    do{right--;}while(nums[right]== nums[right+1] && right > left);
		}
		else
		{
		    do{left++;}while(nums[left] == nums[left-1] && left < right);
		}
	   }
	}
	return c;
    }
};
