/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (30.74%)
 * Total Accepted:    87.2K
 * Total Submissions: 283.5K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
	//this is actually implementation of Boyer Moore Majority vote algorithm
	//to achieve the O(N) and O(1) solution
	//as there are at most two numbers which appear more than n/3
	//we need to find the most likely two candidates
	//the candidates can be init as 0 and 1 and scan the vector
	//in the first pass, in which
	//cnt1 and cnt2 is to track the appearence of the candicate 
	//and update the candicates once cnt1 or cnt2 reaches zero, 
	//meaning the non-candidates consumed the positions
	int cnt1 = 0, cnt2 = 0, a = 0, b = 1;
	int len = nums.size();

	//first pass, select the most likely two candidates
	for(int i = 0; i < len; i++)
	{
	    if(nums[i] == a)
		cnt1++;
	    else if(nums[i] == b)
		cnt2++;
	    else if(cnt1 == 0)
	    {
		cnt1 = 1;
		a = nums[i];
	    }
	    else if(cnt2 == 0)
	    {
		cnt2 = 1;
		b = nums[i];
	    }
	    else
	    {
		cnt1--;
		cnt2--;
	    }
	}

	//second pass, count the actuall appearence of a and b
	cnt1 = cnt2 = 0;
	for(auto n : nums)
	{
	    if(n == a) cnt1++;
	    else if(n == b) cnt2++;
	}

	vector<int> result;
	if (cnt1 > len/3) result.push_back(a);
	if (cnt2 > len/3) result.push_back(b);
	return result;
    }
};
