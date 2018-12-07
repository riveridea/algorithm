/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (43.10%)
 * Total Accepted:    208.5K
 * Total Submissions: 483.7K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
	vector<vector<int>>  r(numRows);
	//the first colum is always 1
	//the next one is equal to the left value of last row plus the upper value of the last row
	for(int i = 0; i < numRows; i++)
	{
	    r[i].resize(i+1);
	    r[i][0] = r[i][i] = 1;

	    for(int j = 1; j < i; j++)
	    {
		r[i][j] = r[i-1][j-1] + r[i-1][j];
	    }
	}
	return r;
    }
};





