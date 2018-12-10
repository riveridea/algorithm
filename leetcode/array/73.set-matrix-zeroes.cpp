/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (38.18%)
 * Total Accepted:    174.5K
 * Total Submissions: 457K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
	//the intersting solution is to record the first element of row and column if a zero is found 
	//in position m[row][col]
	//BUT, there is an important corner case you should not forget
	//the m[0][0] could be impacted by the first row and the first column in the same time
	//thus, we need an extra flag to tell if the first column is marked as zero while keep the
	//m[0][0] only representing the first row
	bool isfirstCol = false;		
	if(ma.empty()) return;
	int m = ma.size();
	int n = ma[0].size();

	//preprocessing 
	for(int i = 0; i < m; i++)
	{
	    if(ma[i][0] == 0) isfirstCol = true;

	    for(int j = 1; j < n; j++)
	    {
		if(ma[i][j] == 0)
		{
		    ma[0][j] = 0;
		    ma[i][0] = 0;
		}
	    }
	}

	//start marking the zeros
	for(int i = 1; i < m; i++)
	{
	    for(int j = 1; j < n; j++)
	    {
		if(ma[0][j] == 0 || ma[i][0] == 0)
		    ma[i][j] = 0;
	    }
	}

	//check the first row and first column
	if(ma[0][0] == 0)
	{
	    for(int j = 1; j < n; j++)
	    {
		ma[0][j] = 0;
	    }
	}

	if(isfirstCol)
	{
	    for(int i = 0; i < m; i++)
	    {
		ma[i][0] = 0;
	    }
	}
    }
};





































