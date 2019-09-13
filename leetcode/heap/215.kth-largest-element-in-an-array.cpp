/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 * algorithms
 * Medium (39.85%)
 * Total Accepted:    168.5K
 * Total Submissions: 423K
 * Testcase Example:  '[1]\n1'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
    //return the positon where the pivot final sits
    int partition(vector<int>& nums, int left, int right)
    {
	int pivot = nums[left];
	int l = left + 1, r = right;	
	while(l <= r)
	{
	    //if l and r both conflict, then swap and GO AHEAD
	    //else if l meets JUST go ahead, r meets JUST go ahead
	    //no meets, stay 
	    if(nums[l] < pivot && nums[r] > pivot)
	    {
		swap(nums[l++], nums[r--]);
	    }

	    if(nums[l] >= pivot) l++;
	    if(nums[r] <= pivot) r--;
	}
	swap(nums[left], nums[r]);
	return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
	//use sorting, the idea is that the K th largest element should be in the k-1 index
	//but you don't need to do fully sorting
	//use quick sorting, each time use a pivot, then partion the elements
	//if the pivot is exactly the k-1 position, return the pivot
	//otherwise, if the pivot is at position larger than k-1 position,
	//it means the answer is in the left partition, 
	//else the answer is in the right partition
	int left = 0, right = nums.size() - 1;
	while(1)
	{
	    int pos = partition(nums, left, right);

	    if(pos == k-1) return nums[pos];
	    else if(pos > k-1) 
	    {
		right = pos - 1;
	    }
	    else
	    {
		left = pos + 1;
	    }
	}
    }
};
