/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (42.85%)
 * Total Accepted:    56.2K
 * Total Submissions: 131K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array which consists of non-negative integers and an integer m, you
 * can split the array into m non-empty continuous subarrays. Write an
 * algorithm to minimize the largest sum among these m subarrays.
 * 
 * 
 * Note:
 * If n is the length of array, assume the following constraints are
 * satisfied:
 * 
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 * 
 * 
 * 
 * Examples: 
 * 
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 * 
 * Output:
 * 18
 * 
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 * 
 * 
 */
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
	//try the dynamic programming 
	//f[i][j] - maximum largest subarray from firtst element of nums to the ith element of nums with j parts
	//fi[i][j] = max(f[k][j-1], sum(k+1,...,i)), thus f[0][0] = 0 and f[n][m] is the answer
	int n = nums.size();
	vector<vector<int>> f(n+1, vector<int>(m+1, INT_MAX));
	vector<long> sums(n+1, 0); //sums[i] mean the sum of the first i elemetns, thus sums[0] = 0;
	for(int i = 0; i < n; i++){
	    sums[i+1] = sums[i] + nums[i];
	}

	//do the dynamic programming
	f[0][0] = 0;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= m; j++){
		for(int k = 0; k < i; k++){
		    f[i][j] = min(f[i][j], max(f[k][j-1], (int)(sums[i] - sums[k])));
		}
	    }
	}
	return f[n][m];
    }
};



































