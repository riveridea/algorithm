/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (38.65%)
 * Total Accepted:    114.6K
 * Total Submissions: 296.4K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
	//binary search, but considering duplicates, compare mid to end but including the == 
	int left = 0, right = nums.size() - 1;

	while(left < right)
	{
	    if(nums[left] < nums[right]) break;  //hit a increasing area, just output 
	    int mid = left + (right - left)/2;
	    if(nums[mid]  > nums[right])
	    {
		left = mid+1;  //mid is not the solution
	    }
	    else if(nums[mid] == nums[right])  // at this point the numbers between mid and right can only be greater or equal to mid
	    {
		left++;   //the point at left can only be greater or equal to mid
		right--;
	    }
	    else
		right = mid;
	}
	return nums[left];
    }
};

























