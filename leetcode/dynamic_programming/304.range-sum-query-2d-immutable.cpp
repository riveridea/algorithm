/*
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (29.48%)
 * Total Accepted:    54.8K
 * Total Submissions: 185.8K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 * 
 * 
 * 
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 * 
 * Example:
 * 
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 * 
 * 
 */
class NumMatrix {
public:
    vector<vector<int>> f;
    NumMatrix(vector<vector<int>> matrix) {
	//define f[i][j] - the sum from (0,0) to (i,j)        
	//f[i][j] = f[i-1][j] + Sum_at_row_i
	//sumRegion(i1,j1, i2,j2)
	//= f(i2,j2) - (f(i2,j1-1) + f(i1-1,j2) - f(i1-1, j1-1))
	//in the constructor, initialize the f[m+1][n+1]
	int m = matrix.size();
	if (m == 0) return;
	int n = matrix[0].size();
	if(n == 0) return;

	f.resize(m+1);
	for(int i = 0; i < m+1; i++)
	{
	    f[i].resize(n+1, 0);
	}
	//initialzie the first row
	f[1][1] = matrix[0][0];
	for(int j = 1; j < n+1; j++)
	{
	    f[1][j] = f[1][j-1] + matrix[0][j-1];	
	    cout << "f[1][" << j << "]=" << f[1][j] << " "; 
	}
	cout << endl;

	for(int i = 2; i < m+1; ++i)
	{
	    int rowSum = 0;
	    for(int j = 1; j < n+1; ++j)
	    {
		rowSum += matrix[i-1][j-1];
		f[i][j] = f[i-1][j] + rowSum;
		cout << i << j << ":" << f[i][j] << "|";
	    }
	    cout << endl;
	}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
	return f[row2+1][col2+1] - (f[row2+1][col1] + f[row1][col2+1] - f[row1][col1]);   
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
