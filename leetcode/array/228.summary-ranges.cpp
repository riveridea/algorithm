/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (34.27%)
 * Total Accepted:    116.3K
 * Total Submissions: 339.4K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 * 
 * Example 1:
 * 
 * 
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 * 
 * 
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
	//this should be an easy problem as I think
	//start from 0 to last element
	vector<string> res;
	int n = nums.size();
	if(n == 0) return res; 

	int start = 0, end = 0;  //each interval
	int i = 0;
	while(i < n)
	{
	    start = end = i; 
	    while(end < n - 1 && nums[end + 1] == nums[end] + 1) end++;

	    if(start < end) 
	    {
		res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
	    }
	    else
	    {
		res.push_back(to_string(nums[start]));
	    }
	    i = end+1; //next possible interval
	}
	return res;
    }
};
