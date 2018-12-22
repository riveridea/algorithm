/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (26.98%)
 * Total Accepted:    49.4K
 * Total Submissions: 183.3K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1, 5, 1, 1, 6, 4]
 * Output: One possible answer is [1, 4, 1, 5, 1, 6].
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1, 3, 2, 2, 3, 1]
 * Output: One possible answer is [2, 3, 1, 3, 1, 2].
 * 
 * Note:
 * You may assume all input has valid answer.
 * 
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
	//this problem is almost the hardest problem I ever met
	//firstly find a median that half of the numbers are greater than it.
	//then as we know, we can put the greater ones to the position of odd index
	//the less ones will be put the even index, and the rest index store the equal 
	//thus, there is a 3-way partition method to re-partition the numbers to 3 areas:
	//1. odd index - greater than median
	//2. even index - less than median
	//3. the rest of - equal to median
	//however, this partiion is different to the normal 3-way partition, in which left, middle,
	//and right  are 3 area. 
	//But, a mapping of the index can be used to map the odd index to left, even index to right,
	//and rest to the middel.
	//the mapping from the original index to mapped index is like
	//mi = (2*i+1)%(n|1)
	//mi is actuall the target index of the nums[i], n|1 is to for the nearest odd no less than n
	//Before the partion, we know the nums[i] storing the targeted number, and for i, the targeted
	//index mi is not storign the targeted number, thus we need to go thru each targeted postion 
	//to compare the current with median, if greater, should swap to the (odd)left area, 
	//if less, then should swap to the (even)right area, et..
	//This is an equivalent 3-way partition. 
	int n = nums.size();
	if(n == 0) return;
	//step 1: Find the median
	vector<int>::iterator nth = next(nums.begin(), n/2);
	nth_element(nums.begin(), nth, nums.end());
	int median = *nth;

	//perform an equvalent 3-way partition, with mapped (equavlent) indexed elements
	auto m = [n](int idx) {return (2*idx +1)%(n|1);};  //lambda function

	//left is the boudnary of greater ones
	//right is the boudnary of less ones
	int left = 0, right = n -1, c = 0; //c is candidated 
	while(c <= right)
	{
	    if(nums[m(c)] > median)
	    {
		swap(nums[m(c)], nums[m(left)]);
		c++;
		left++;
	    }
	    else if (nums[m(c)] < median)
	    {
		swap(nums[m(c)], nums[m(right)]);
		right--;
	    }
	    else
		c++;
	}
    }
};



















