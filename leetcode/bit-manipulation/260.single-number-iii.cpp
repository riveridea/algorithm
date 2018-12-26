/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (55.34%)
 * Total Accepted:    95.8K
 * Total Submissions: 173.1K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
	//recall the if there is only one distinct number, we can xor all the numbers
	//and return the final result
	//now we need to return 2 numbers, how about to divide the numbers to two group
	//each containing 1 result. How to divide?
	//we firstly xor all the numbers and the result is the xor result of the two 
	//different numbers
	//the second pass is to separate two groups
	//at least one bit of the xor result of the last pass, we find the right most
	//1 bit. For a and b, for that the 1 bit, the bit at a and b must be different. 
	//So all the numbers & this mask as zero is set to as the group 1, and the rest
	//in the group 2. 
	int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
	diff &= -diff; // only the right most 1 is left in the diff

	vector<int> res(2,0);
	//xor to different group based on the & of diff
	for(auto n : nums)
	{
	    if((n & diff) == 0)
		res[0] ^= n;
	    else 
		res[1] ^= n;
	}
	return res;
    }
};

















