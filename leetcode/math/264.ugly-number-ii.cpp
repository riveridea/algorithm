/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (34.85%)
 * Total Accepted:    91.1K
 * Total Submissions: 261.3K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */
class Solution {
public:
    int nthUglyNumber(int n) {
	//any ugly number can be express as smaller ugly number by 2 or 3, or 5;
	//thus select the minimum number of L1*2, L2*3, L3*5
	//the key is, if we have a array k representing the known ugly number
	//L1, L2, L3 could start from K[0], k[0], k[0], which means t1, t2, t3 
	//start from 0, and only increments when the k[t_i] is select as the next
	//ugly number
	if(n == 0) return 0;

	int t1 = 0, t2 = 0, t3 = 0;
	vector<int> k(1,1); // the first ugly number is 1
	
	for(int i = 1; i < n; i++) //stop at n_th ugly number
	{
	    int k1 = k[t1]*2;
	    int k2 = k[t2]*3;
	    int k3 = k[t3]*5;
	    int m = min(k1, min(k2, k3));
	    
	    if(m == k1) t1++;
	    if(m == k2) t2++;
	    if(m == k3) t3++;

	    k.push_back(m);
	}
	return k[n-1];
    }
};
