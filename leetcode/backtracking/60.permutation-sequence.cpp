/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (30.93%)
 * Total Accepted:    116.5K
 * Total Submissions: 376.5K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

/**
 * kangtuo coding method
 *
 * a1 = k1/(n-1)!, k1 = k
 * a2 = k2/(n-2)!, k2 = k1%(n-1)
 *
 *
 * thus we have k = k%base, base /= i
 */

class Solution {
public:
    string getPermutation(int n, int k) {
	//firstly construct an initial string
	string s(n, '0');
	string result;
	for (int i = 0; i<n; i++)
	{
	    s[i] += i + 1; 
	}

	return k_permutation(s, k);
    }
private:
    int factorial(int n)
    {
	int result = 1;
	for(int i = 1; i <= n; ++i)
	{
	    result *= i; 
	}

	return result;
    }


    string k_permutation(string &s, int k)
    {
	string result;
	const int n = s.size();
	int base = factorial(n - 1);

	--k; //the conto algorithm, k starts from 0
	for(int i = n-1; i >0; k %= base, base /= i, --i)
	{
	    //find a in the string
	    auto a = next(s.begin(), k/base);
	    result.push_back(*a);
	    //remove a as a is no longer invivoling in subsequent permutation
	    s.erase(a);
	}

	result.push_back(s[0]);

	return result;
    }
};
