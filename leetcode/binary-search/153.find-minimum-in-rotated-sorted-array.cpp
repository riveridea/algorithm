/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (41.82%)
 * Total Accepted:    234.5K
 * Total Submissions: 560.8K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
	//if scan the array from left to right, then O(n)
	//you can use the binary search
	//find the folding point
	int left = 0, right = nums.size() - 1;
	if(right < 0) return 0;
	if(right == 0) return nums[0];
	if(right == 1) return min(nums[0], nums[1]);
	
	while(left < right)
	{
	    int mid = left + (right - left)/2;
	    if(nums[mid] < nums[right])
	    {
		right = mid;
	    }
	    else
	    {
		left = mid + 1;	
	    }
	}

	return nums[right];
    }
};
