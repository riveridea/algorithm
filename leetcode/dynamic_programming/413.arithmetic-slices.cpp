/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 *
 * https://leetcode.com/problems/arithmetic-slices/description/
 *
 * algorithms
 * Medium (54.75%)
 * Total Accepted:    53.2K
 * Total Submissions: 97.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * A sequence of number is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7 
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that
 * array is any pair of integers (P, Q) such that 0 
 * 
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * ⁠   A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this
 * means that P + 1 < Q.
 * 
 * The function should return the number of arithmetic slices in the array
 * A. 
 * 
 * 
 * Example:
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3,
 * 4] itself.
 * 
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
	//this is typical DP problem
	//define dp[i] as the number of Arithmetics ending at A[i], and A[i] must be included
	//then from bottomer to up, update dp[i+1] according the difference
	//between A[i], A[i-1] and A[i+1]
	int n = A.size();
	if(n < 3) return 0;
	//vector<int> dp(n, 0); 
	
	int result = 0;
	int curr = 0;
	if(A[2] - A[1] == A[1] - A[0]) curr = 1;
	result += curr;
	for(int i = 3; i < n; i++)
	{
	    if(A[i] - A[i-1] == A[i-1] - A[i-2])
		curr = curr + 1;
	    else
		curr = 0;

	    result += curr;
	}

	return result;
    }
};





























