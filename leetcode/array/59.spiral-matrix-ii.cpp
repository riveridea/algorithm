/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (44.09%)
 * Total Accepted:    119.6K
 * Total Submissions: 271.2K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
	//the key idea is to process 4 segments in each loop
	//horizontal, left to right
	//vertical, top to down
	//horizontal, right to left
	//vertical, down to top
	vector<vector<int>> result(n, vector<int>(n,0));
	int index = 1;
	int i = 0; //starting row
	while(index <= n*n)
	{
	    int j = i; 
	    while(j < n-i)
		result[i][j++] = index++;
	    
	    j = i+1;
	    while(j < n-i)
		result[j++][n-i-1] = index++;

	    j = n - i - 2;
	    while(j > i)
		result[n-i-1][j--] = index++;

	    j = n- i - 1;
	    while(j > i)
		result[j--][i] = index++;

	    i++; // to next loop (circle)
	}
	return result;
    }
};


























