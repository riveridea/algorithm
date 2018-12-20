/*
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (39.94%)
 * Total Accepted:    54.2K
 * Total Submissions: 135.8K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * Write a program to find the nth super ugly number.
 * 
 * Super ugly numbers are positive numbers whose all prime factors are in the
 * given prime list primes of size k.
 * 
 * Example:
 * 
 * 
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32 
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 
 * ⁠            super ugly numbers given primes = [2,7,13,19] of size 4.
 * 
 * Note:
 * 
 * 
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 * The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
	//this problem is almost the same as the 306, ugly number ii
	vector<int> index(primes.size(), 0);  //define so many index to track the index in selecting the minimum of ugly number
	vector<int> ugly(n, INT_MAX); //all initialized to INT_MAX
	ugly[0] = 1;
	for(int i = 1; i < n; i++) 
	{
	    for(int j = 0; j < primes.size(); j++)
		ugly[i] = min(ugly[i], ugly[index[j]]*primes[j]);

	    for(int j = 0; j < primes.size(); j++)
	    {
		if(ugly[i] == ugly[index[j]]*primes[j])
		{
		    index[j]++;
		}
	    }
	}
	return ugly[n-1];
    }
};
