/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (48.11%)
 * Total Accepted:    65.2K
 * Total Submissions: 135.5K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1:
 * 
 * 
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * Example 2:
 * 
 * 
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
	//recursive, and divie and conquer
	// divide the input string to two parts everytime we meet a  operator
	// then try every combinations to get the results
	vector<int> result;
	for(int i = 0; i < input.size(); i++)
	{
	    char c = input[i];
	    if (ispunct(c))
	    {
		vector<int> firsthalf = diffWaysToCompute(input.substr(0,i));
		vector<int> secondhalf = diffWaysToCompute(input.substr(i+1));
		for(auto a : firsthalf)
		    for(auto b : secondhalf)
			result.push_back(c=='+' ? a+b : c=='-'? a-b: a*b);	
	    }
	}
	return result.size()?result:vector<int>{stoi(input)};
    }
};
