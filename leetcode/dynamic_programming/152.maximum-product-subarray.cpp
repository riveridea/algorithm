/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray
 *
 * algorithms
 * Medium (26.24%)
 * Total Accepted:    120.3K
 * Total Submissions: 458.3K
 * Testcase Example:  '[-2]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 * 
 * 
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 * 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
	//dynamic programming
	//aj could be the end of previous array or new start of the new array for an answer
	int maxLocal = nums[0];
	int minLocal = nums[0]; 
	int global = nums[0];

	for(int i = 1; i < nums.size(); i++)
	{
	    int temp = maxLocal;
	    //first select the max from all possible options
	    maxLocal = max(maxLocal*nums[i], max(nums[i], minLocal*nums[i]));
	    //also need to compute the minimum, consider the product
	    minLocal = min(temp*nums[i], min(nums[i], minLocal*nums[i]));
	    global = max(global, maxLocal);
	}
	return global;	
    }
};
