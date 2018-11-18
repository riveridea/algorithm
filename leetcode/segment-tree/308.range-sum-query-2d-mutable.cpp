/*
 * [308] Range Sum Query 2D - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-mutable/description/
 *
 * algorithms
 * Hard (29.21%)
 * Total Accepted:    29.5K
 * Total Submissions: 101.1K
 * Testcase Example:  '["NumMatrix","sumRegion","update","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[3,2,2],[2,1,4,3]]'
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
 * update(3, 2, 2)
 * sumRegion(2, 1, 4, 3) -> 10
 * 
 * 
 * 
 * Note:
 * 
 * The matrix is only modifiable by the update function.
 * You may assume the number of calls to update and sumRegion function is
 * distributed evenly.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 * 
 * 
 */
class NumMatrix {
private:
    vector<vector<int>> tree; //2D segment tree
    int m; //row size
    int n; //column size 

public:
    NumMatrix(vector<vector<int>> matrix) {
	//2D segment tree    
	m =  matrix.size();
	n = m == 0 ? 0:matrix[0].size();
	
	if(matrix.empty()) return;

	//build the 2D segment tree
	//step 1 construct the 1D tree for each row
	//and also the leaves of the 2D tree
	tree.resize(2*m);
	for(int i = m; i < 2*m; i++)
	{
	    tree[i].resize(2*n, 0);
	    //insert the leaves
	    for(int j = n; j < 2*n; j++)
		tree[i][j] = matrix[i-m][j-n];

	    //calcualte the parents
	    for(int k = n-1; k >= 1; k--)
	    {
		tree[i][k] = tree[i][2*k] + tree[i][2*k+1];
	    }
	}
	//step 2, finish the 2D segment tree, which is actually 
	//calculate the parents
	for(int l = m-1; l >= 1; l--)
	{
	    tree[l].resize(2*n, 0);
	    for(int p = 0; p < 2*n; p++)
		tree[l][p] = tree[2*l][p] + tree[2*l+1][p]; 
	}
    }
    
    void update(int row, int col, int val) {
	//firstly find the leaf of the 2D segment tree
	//then find leaf in the 1D segment tree
	int pos1 = row + m;
	int pos2 = col + n;
	tree[pos1][pos2] = val;
	//move forward to update the parents
	//1. update the parents 1D segment tree
	for(int i = pos2; i > 1; i>>=1)
	{
	    tree[pos1][i>>1] = tree[pos1][i] + tree[pos1][i^1];
	}
	//2. update the parents in 2D segment tree
	for(int j = pos1; j > 1; j>>=1)
	{
	    for(int p = 0; p < 2*n; p++)
		tree[j>>1][p] = tree[j][p] + tree[j^1][p];
	}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
	vector<int> result_v(2*n, 0);	 
	//find the target 2d result firstly
	int up = row1 + m, down = row2 + m;
	while(up <= down)
	{
	    if(up&1)
	    {
		for(int i = 0; i < 2*n; i++)	
		{
		    result_v[i] += tree[up][i];
		}
		up++;
	    }
	    up >>= 1;
	    if(!(down&1))
	    {
		for(int i = 0; i < 2*n; i++)
		{
		    result_v[i] += tree[down][i];
		}
		down--;
	    }
	    down >>= 1;
	}
	//now get the 1d sum result
	int left = col1 + n, right = col2 + n;
	int result = 0;
	while(left <= right)
	{
	    if(left&1) result += result_v[left++];
	    left >>= 1;
	    if(!(right&1)) result += result_v[right--];
	    right >>= 1;
	}
	return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
