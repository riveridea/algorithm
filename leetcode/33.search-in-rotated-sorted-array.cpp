/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array
 *
 * algorithms
 * Medium (32.04%)
 * Total Accepted:    206.5K
 * Total Submissions: 644.3K
 * Testcase Example:  '[]\n5'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	//use binary search to narrow down the searching area         
    	int l = 0, r = nums.size()-1;
	
	while(l < r)
	{
	    int mid = l + (r - l)/2;
	    //find the next searching area
	    if(target == nums[mid])
		return mid;

	    //go ahead 
	    if(nums[mid] > nums[r])
	    { //roation is exactly right after mid
	    
	    }
	    else if(nums[mid] < nums[l])
	    { //roation is exactly before mid
		if()
	    }
	}
    }
};
