/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (24.71%)
 * Total Accepted:    112.9K
 * Total Submissions: 457K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
	//this is an interesting sorting probelm
	//think about only two string, how to determin if one string is greater than
	//the other one?
	//s1 + s2  > s2 + s1 => s1 > s2
	vector<string> array;
	for(auto i:nums)
	{
	    array.push_back(to_string(i));
	}
	//sort
	sort(array.begin(), array.end(), [](string &s1, string&s2){return s1+s2 > s2+s1;});

	string result;
	for(auto s: array)
	{
	    result += s;
	}

	//remvoe the first all zeros
	while(result[0] == '0' && result.size()>1)
	{
	    result.erase(0,1);
	}
	return result;
    }
};
