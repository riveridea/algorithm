/*
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.42%)
 * Total Accepted:    186.6K
 * Total Submissions: 542.1K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	//binary search 
	//the range would be 0 - m*n, just think about to conver the 
	//1d index to 2d indexes
	int m = matrix.size();
	if (m == 0) return false;
	int n = matrix[0].size();
	if (n == 0) return false;
	
	int start = 0;
	int end = m*n;

	while(start < end)
	{
	    int mid = start + (end - start)/2;
	    int value = matrix[mid/n][mid%n];

	    if(target == value) return true;

	    if(target > value)
	    {
		start = mid+1;
	    }
	    else
	    {
		end = mid;
	    }
	}
	return false;
    }
};
