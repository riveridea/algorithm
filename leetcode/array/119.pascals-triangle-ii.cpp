/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (40.74%)
 * Total Accepted:    171K
 * Total Submissions: 419.8K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the kth index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
	//actually this could be a 2D dynamic programming with optimization to 1D
	//with only k extra space
	int k = rowIndex + 1;
	vector<int> result(k, 0);
	if(k == 0) return result;

	result[0] = 1;
	int curr = 0, prev = 0; 
	for(int i = 0; i < k; i++)
	{ 
	    prev = result[0];
	    result[i] = 1;
	    for(int j = 1; j < i; j++)
	    {
		curr = result[j];  //record this as result[i-1][j-1] 
		result[j] = result[j] +	prev;
		prev = curr;
	    }
	}
	return result;
    }
};


















