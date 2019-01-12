/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (44.67%)
 * Total Accepted:    34.6K
 * Total Submissions: 77.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * Output:  [1,2,4,7,5,3,6,8,9]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	//this is a pure index arithmetic problem
	//iterate row and column following the rule:
	//if r + c is even, means we are moving up, otherwise we are moving down
	//when hitting the edge of row, then column increases, vice versa.
	//considering hitting edge in diffrent areas, like the left upper half
	//and righ down half 
	vector<int> result;
	if(matrix.empty()) return result;
	int m = matrix.size();
	int n = matrix[0].size();

	int r = 0, c = 0; //let us start from matrix[0][0]
	for(int i = 0; i < m*n; i++)
	{
	    result.push_back(matrix[r][c]);
	    if((r+c)%2 == 0) //moving up
	    {
		if(c == n-1) r++;
		else if(r == 0) c++;
		else
		{
		    r--;
		    c++;
		}
	    }
	    else
	    {
		if(r == m-1) c++;
		else if(c == 0) r++;
		else
		{
		    r++;
		    c--;
		}
	    }
	}
	return result;
    }
};
