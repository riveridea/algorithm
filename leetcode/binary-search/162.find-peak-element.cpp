/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (40.12%)
 * Total Accepted:    196K
 * Total Submissions: 488.7K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Note:
 * 
 * Your solution should be in logarithmic complexity.
 * 
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
	//this is binary search, though it is not sorted array, but as the problem just 
	//ask an arbitary peak, actaully for any a b c whose value is not idential to neigbors
	//you can alwyas find a peak
	int low = 0, high = nums.size() -1;
	while(low < high - 1) // this is important to avoid low = high - 1, then just to compare low and high  
	{
	    int mid = low + (high - low)/2;
	    if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
	    {
		return mid;
	    }
	    else if(nums[mid] > nums[mid+1]) //this means nums[mid-1] is highest for mid and mid's neighbors
	    {
		high = mid - 1;	// this means high is greater than its right one
	    }
	    else
		low = mid + 1; // this means low is greater than its left one
	}
	//cout << low << high << endl;
	//now low is high or low is high - 1, rember each high is greater than its right, low is greater than its left
	return nums[low] > nums[high] ? low : high;
    }
};
