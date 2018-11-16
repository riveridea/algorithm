/*
 * [325] Maximum Size Subarray Sum Equals k
 *
 * https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.79%)
 * Total Accepted:    65.3K
 * Total Submissions: 149.1K
 * Testcase Example:  '[1,-1,5,-2,3]\n3'
 *
 * Given an array nums and a target value k, find the maximum length of a
 * subarray that sums to k. If there isn't one, return 0 instead.
 * 
 * Note:
 * The sum of the entire nums array is guaranteed to fit within the 32-bit
 * signed integer range.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1, -1, 5, -2, 3], k = 3
 * Output: 4 
 * Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-2, -1, 2, 1], k = 1
 * Output: 2 
 * Explanation: The subarray [-1, 2] sums to 1 and is the longest.
 * 
 * Follow Up:
 * Can you do it in O(n) time?
 * 
 */
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
	//record a value for each i, defined as the sum 
	//since the left
	//then every time find a paired j (j < i) which 
	//has sum as k - sumofi, then update max_len
	//this is O(n)
	int n = nums.size();
	if (n == 0) return 0;
	unordered_map<int, int> sums;
	int curr_sum = 0;
	int max_len = 0;

	for(int i = 0; i < n; i++)
	{
	    curr_sum += nums[i];
	    if(curr_sum == k)
	    {
		max_len = i+1; // i - 0
	    }
	    else
	    {
		//check if we have pair
		if(sums.find(curr_sum - k) != sums.end())
		{
		    max_len = max(max_len, i - sums[curr_sum-k]); // no +1,as it is excluded
		}
	    }

	    //only insert when it does not exists, the oldest i is recorded
	    if(sums.find(curr_sum) == sums.end())
		sums[curr_sum] = i;
	}
	
	return max_len;
    }
};
