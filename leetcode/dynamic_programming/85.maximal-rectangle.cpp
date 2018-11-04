/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle
 *
 * algorithms
 * Hard (28.87%)
 * Total Accepted:    77K
 * Total Submissions: 266.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 6.
 * 
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
	//find each rectangle represented by H*(R - L) at each '1' 
	//define H[j] - the height of all '1' at each j in [0, n]
	//define R[j] - the right position of all '1'
	//define L[j] - the left position of all '1'
	//notice the H, R, L for each j could be changed 
	//when traversal to next rectangle
	//so the answer could be updating for each [i,j]
	int m = matrix.size();
	if(m == 0) return 0;
	int n = matrix[0].size();
	if(n == 0) return 0;
	int ret = 0;
	vector<int> H(n, 0);
	vector<int> L(n, 0);
	vector<int> R(n, n);

	//traversal every row
	for(int i = 0; i < m; i++)
	{
	    int right = n, left = 0;
	    //in each row
	    //firstly calculate the L[j] from the left to right
	    int j = 0;
	    for(j = 0; j < n; j++)
	    {
		//'1' is met, increase the Height
		if(matrix[i][j] == '1')
		{
		    ++H[j];
		    L[j] = max(L[j], left);
		}
		else // '0' is met, reset the height 
		{
		    //find a candidate of left
		    left = j + 1;
		    H[j] = 0; L[j] = 0; R[j] = n;
		}
	    }
	    
            //secondly calculate the R[j] form the right to left
	    for(j = n -1; j >= 0; --j)	    
	    {
		//'1' is met, increase the Height
		if(matrix[i][j] == '1')	
		{
		    R[j] = min(R[j], right);
		    ret = max(ret, H[j]*(R[j]-L[j]));
		}
		else
		{
		    right = j;
		}
	    }
	}	    
	return ret;
    }
};
