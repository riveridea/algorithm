/*
 * [259] 3Sum Smaller
 *
 * https://leetcode.com/problems/3sum-smaller/description/
 *
 * algorithms
 * Medium (43.54%)
 * Total Accepted:    44.2K
 * Total Submissions: 101.4K
 * Testcase Example:  '[-2,0,1,3]\n2'
 *
 * Given an array of n integers nums and a target, find the number of index
 * triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i]
 * + nums[j] + nums[k] < target.
 * 
 * Example:
 * 
 * 
 * Input: nums = [-2,0,1,3], and target = 2
 * Output: 2 
 * Explanation: Because there are two triplets which sums are less than
 * 2:
 * [-2,0,1]
 * ⁠            [-2,0,3]
 * 
 * 
 * Follow up: Could you solve it in O(n2) runtime?
 * 
 */
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
	//two pointers,
	//fix the first i
	//left = i +1
	//right = n -1        
	//i will end with n - 3
	int n = nums.size();
	if(n == 0) return 0;
	
	int result = 0;
	//sort!!!!!
	sort(nums.begin(), nums.end());
	for(int i = 0; i < n - 2; i++)
	{
	    int left = i + 1, right = n - 1;
	    while(left < right)
	    {
		if(nums[i] + nums[left] + nums[right] < target)
		{
		    result += right - left; //all the third less than right are also in the answers
		    ++left;
		}
		else
		{
		    --right;
		}
	    }
	}
	return result;
    }
};
