/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.23%)
 * Total Accepted:    353.8K
 * Total Submissions: 1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //let's implement the lower_bound and upper_bound manauly 
        //support the nums is already sorted
        vector<int> res({-1, -1});
        int n = nums.size();
        if(n == 0) return res; 
        if(target < nums[0] || target > nums[n-1]) return res;
        
        int low = l_bound(nums, target);
        int upper = u_bound(nums, target);
        if(nums[low] == target) 
        {
            res[0] = low;
            res[1] = upper - 1;
        }
        return res;
    }

    int l_bound(vector<int>& nums, int target){
        int l = 0;
        int h = nums.size(); // not n-1
        while(l < h){
            int mid = l + (h-l)/2;
            if(target <= nums[mid])
        	h = mid;
            else
        	l = mid + 1;
        }
        return h; //it doesn't matter h or l
    }

    int u_bound(vector<int>& nums, int target){
        int l = 0;
        int h = nums.size(); //not n-1
        while(l < h){
            int mid = l + (h-l)/2;
            if(target >= nums[mid])
        	l = mid+1;
            else
        	h = mid;
        }
        return l; //it doesn't matter h or l
    }
};
