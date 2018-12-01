/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (39.66%)
 * Total Accepted:    144.1K
 * Total Submissions: 363.2K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mx, int target) {
	//intersting solution, you cannot use 2 roudn binary search
	//as the fisrt element of the row is not necessary greater than
	//the last element if the last row
	//just start form mx[0][n-1], if target is less than mx[0][n-1]
	//obviously it is in row[0], if not just go to the last element 
	//of the next row, if less, in this row, if not go the next row..
	int m = mx.size();
	if(m == 0) return false;
	int n = mx[0].size();
	if(n == 0) return false;

	int i = 0, j = n - 1;
	while(i < m && j >= 0)
	{
	    if(mx[i][j] == target)
	    {
		return true;
	    }

	    if(mx[i][j] > target)
	    {
		j--;
	    }
	    else
	    {
		i++;	
	    }
	}
	return false;
    }
};
