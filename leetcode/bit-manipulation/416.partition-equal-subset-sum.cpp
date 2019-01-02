/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (39.22%)
 * Total Accepted:    66.2K
 * Total Submissions: 168.9K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * 
 * Note:
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
	//you need to find if there are numbers summed to be the half of the total sum        
	//a bitset is used, as the problem tell you that the maximum number is less than 100
	//and no more than 200 numbers in total in the array, so the maximum sum could be 200* 100
	//the bitset size can be 200*100, but actaully not necessary, as we only care about
	//the sum/2. 
	//the bitset is set as size of 200*100/2 + 1, with initialized as 0x1. each time we 
	//shift the bitset nums[i] and or the original bitset to record the possible sum.
	//so, once bit[sum/2] is 1, we know there are sum/2
	bitset<10001> bits(1);
	int sum = 0;
	for(auto n : nums)
	{
	    sum += n;
	    bits |= bits << n;
	}
	
	return !(sum & 1) && bits[sum >> 1];
    }
};




























