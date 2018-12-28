/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (43.90%)
 * Total Accepted:    35.2K
 * Total Submissions: 80.1K
 * Testcase Example:  '13'
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
	//well this is actually a math problem
	//the idea is to find the next added number
	//and it depends upon the n
	//suppose we have 45, we could have next as
	//450, if 45*10 is less than n
	//else 46, if 45%10 != 9 and 45 +1 is less than n 
	//else 5, if 45/10 +1 and 5 is less than n (n = 451)
	//the other case is 499, n = 600, 499/10/10 + 1, next is 5
	//just check these cases in a sequence 
	vector<int> result;
	int curr = 1;
	for(int i = 1; i <= n; i++)
	{
	    result.push_back(curr);
	    if(curr*10 <= n)
		curr *= 10;
	    else if(curr%10 != 9 && curr + 1 <= n)
		curr++;
	    else 
	    {
		while(curr%10 == 9 || curr == n)
		{
		    curr /= 10;
		}
		curr++;
	    }
	}
	return result;
    }
};
