/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (34.74%)
 * Total Accepted:    113.1K
 * Total Submissions: 325.6K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */
class NumArray {
public:
    vector<int> f;
    NumArray(vector<int> nums) {
	//f[i] is defined as sum from 0 to i 
	//f[i] = f[i-1] + nums[i]
	//thus sum[i,j] = f[j] - f[i-1]
	if(nums.size() == 0)
	    return;
	f.resize(nums.size(), 0);
	f[0] = nums[0];
	for(int i = 1; i < nums.size(); i++)
	{
	    f[i] = f[i-1] + nums[i];
	}
    }
    
    int sumRange(int i, int j) {
	return f[j] - (i == 0 ? 0: f[i-1]); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
