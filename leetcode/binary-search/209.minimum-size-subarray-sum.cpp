/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (33.47%)
 * Total Accepted:    146.7K
 * Total Submissions: 438.2K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
	//two pointers
	int n = nums.size();
	if(n == 0) return 0;

	int l = 0;
	int r = 0;	
	int minLen = n+1;
	int sum = 0;

	//start scrambling
	while(r < n)
	{
	    if(sum < s)  
	    {
		sum += nums[r];
		r++;
	    }
	    else
	    {
		minLen = min(minLen, r - l);
		if(r - l == 1) return 1;
		sum -= nums[l];
		l++;
	    }
	}

	//at this time we may get the sum >= s but the min len 
	//could be optimized to the minimum len
	while(sum >= s)
	{
	    minLen = min(minLen, r - l);
	    sum -= nums[l++];
	}

	//must consider if there is no answer, minLen never get decreased from n
	return minLen = (minLen == n+1)?0:minLen;
	
    }
};
