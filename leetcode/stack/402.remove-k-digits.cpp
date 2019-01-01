/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (25.78%)
 * Total Accepted:    48.4K
 * Total Submissions: 187.8K
 * Testcase Example:  '"1432219"\n3'
 *
 * Given a non-negative integer num represented as a string, remove k digits
 * from the number so that the new number is the smallest possible.
 * 
 * 
 * Note:
 * 
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 * 
 * 
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
	//this problem is pretty tricky,
	//as the smallest number can be obtained by keep removing the number whose next is 
	//less than it, unitl k numbers are removed 
	//fox example: 1432219, 4>3, then remove 4, 3>2, remove 3, 2 > 1, remove 2, 3 numbers 
	//are removed, then the result is 1219
	//a stack is used to keep the final result, but can be emualted by the string result
	
	string result = "";
	for(auto c : num)
	{
	    while(result.length() && result.back() > c && k)  //remove all the number in the stack that is greater than c
	    {
		//cout << result.back();
		result.pop_back(); //remove this top
		k--;
	    }

	    if(result.length() || c != '0') result.push_back(c); //the first char cannot be '0'
	}

	while(result.length() && k--) 
	{
	    //cout << result.back();
	    result.pop_back();
	}

	return result.empty() ? "0" : result;
    }
};

























