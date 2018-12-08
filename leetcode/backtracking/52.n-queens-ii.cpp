/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (49.52%)
 * Total Accepted:    87.6K
 * Total Submissions: 176.8K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution {
public:
    int totalNQueens(int n) {
	//well, let us continue use the recursion
	//here the algorithm is actually based on Guass's method
	//use  an array queen[n] to represent the position of queen at row n,
	//-1 would mean there is no queen in this row
	//we define the subproblem as we already have the answer from row 0 to r-1
	//now go ahead to consider row r in which where the queen should be placed 
	//in row r considering the exisiting solutuions in rows 0 to r-1
	//thus once get answer at r, then recurively call r+1, until the we hit the last
	//row, and count the solutions
	if (n == 0) return 0;
	int count = 0;
	vector<int> queen(n, -1);
	dfs(queen, 0, count, n);
	return count;
    }

    void dfs(vector<int>& q, int r, int& res, int n)
    {
	if(r == n) 
	{
	    res++;
	    return;
	}
	else
	{
	    //try each column, once we find an available column at row r,then
	    //place the queen and then dfs to the next row, once finsih the dfs,
	    //need to recover this position, as next column needs to try again
	    for(int j = 0; j < n; j++)
	    {
		bool legal = true;// suppose we need to check if is legal to place a queen on column j at row r
		//let us check the first 0 - r-1 rows to see if any attackers
		if(r > 0)
		    for(int i = 0; i < r; i++) //check the first r-1 rows, i = 0 ~ r-1
		    {
			if(q[i] == j ||    //the same column
			   //q[i] == j - (r - i) || // the left diganal 
		           //q[i] == j + (r - i) )  // the right diagnal
			   abs(q[i] -j) == abs(r - i))
			    legal = false;
		    }

		if(legal == true)
		{
		    //place the queen
		    q[r] = j;
		    //dfs to the next row
		    dfs(q, r+1, res, n);
		    q[r] = -1; 
		}
	    }
	}
    }
};
























