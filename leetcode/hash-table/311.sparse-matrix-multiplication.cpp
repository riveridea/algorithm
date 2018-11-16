/*
 * [311] Sparse Matrix Multiplication
 *
 * https://leetcode.com/problems/sparse-matrix-multiplication/description/
 *
 * algorithms
 * Medium (54.24%)
 * Total Accepted:    56.2K
 * Total Submissions: 103.6K
 * Testcase Example:  '[[1,0,0],[-1,0,3]]\n[[7,0,0],[0,0,0],[0,0,1]]'
 *
 * Given two sparse matrices A and B, return the result of AB.
 * 
 * You may assume that A's column number is equal to B's row number.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * A = [
 * ⁠ [ 1, 0, 0],
 * ⁠ [-1, 0, 3]
 * ]
 * 
 * B = [
 * ⁠ [ 7, 0, 0 ],
 * ⁠ [ 0, 0, 0 ],
 * ⁠ [ 0, 0, 1 ]
 * ]
 * 
 * Output:
 * 
 * ⁠    |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
 * AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
 * ⁠                 | 0 0 1 |
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
	int am = A.size();
	int ak = A[0].size();
	int bk = B.size();
	int bn = B[0].size();

	vector<vector<int>> C(am, vector<int>(bn, 0));

	for(int i = 0; i < am; i++)
	{
	    for(int k = 0; k < ak; k++)
	    {
		if(A[i][k] != 0)
		{
		    for(int j = 0; j < bn; j++)
			C[i][j] += A[i][k]*B[k][j];
		}
	    }
	}

	return C;
    }
};
