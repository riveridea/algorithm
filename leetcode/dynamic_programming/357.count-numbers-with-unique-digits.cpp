/*
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (46.23%)
 * Total Accepted:    55.3K
 * Total Submissions: 119.7K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10n.
 * 
 * 
 * Example:
 * 
 * 
 * Input: 2
 * Output: 91 
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, 
 * excluding 11,22,33,44,55,66,77,88,99
 * 
 * 
 */
class Solution{ 
public:
    int countNumbersWithUniqueDigits(int n) {
	//this problem is actually a math problem
	//f[i] = f[i-1]*(10 - (i-1))
	//i is the number of 0 after 1 
	//if n = 2, then 100 has two 0s
	//think about 10, we have 10 answers
	//think about 100, we have two digits, so each digit will find 9 choice to form a two digits
	//with unique digit, totally we have 9(except the first 0) such cases
	//thnink about 1000, then 3 digits, f[3] = f[2] * (10 -2) because for each first two digits you 
	//will only have 10 - 2 choices for the third digits
	//and so on
	//but for n = 11, means 11 digits but we only have 10 symbols, thus f[11] and so on are 0
	if(n == 0) return 1;
	if(n == 1) return 10;
	
	vector<int> f(n+2, 0);
	f[1] = 10;
	f[2] = 9*9;	
	
	int res = f[1] + f[2];	
	if(n == 2) return res;
	int upper = n <= 10 ? n : 10;
	for(int i = 3; i <= n; i++)
	{
	    f[i] = f[i-1] * (10-i+1);
	    res += f[i];
	}
	return res;
    }
};
