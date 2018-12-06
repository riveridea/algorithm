/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (33.96%)
 * Total Accepted:    298.9K
 * Total Submissions: 880.1K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	//as the nums1 has enough space to contain m + n elements
	//start from the rear, place the bigger one to the target area
	int i1 = m - 1, i2 = n - 1;
	int k = m + n -1;
	while(i2 >= 0) // nums1 not finished
	{
	    if(i1 >= 0 && nums1[i1] > nums2[i2])	
	    {
		nums1[k] = nums1[i1];
		i1--;
	    }
	    else
	    {
		nums1[k] = nums2[i2];
		i2--;	
	    }
	    k--;
	}
    }
};
