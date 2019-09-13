/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (53.97%)
 * Total Accepted:    429.1K
 * Total Submissions: 794.9K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
	//hash map is easy solution
	unordered_map<int, int> h;
	int n = nums.size();
	for(int i = 0; i < n; i++){
	    h[nums[i]]++;
	    if(h[nums[i]] > n/2) return nums[i];
	}
	return 0;
    }
};
