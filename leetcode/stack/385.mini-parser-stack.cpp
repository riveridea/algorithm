/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 *
 * https://leetcode.com/problems/mini-parser/description/
 *
 * algorithms
 * Medium (31.32%)
 * Total Accepted:    26.9K
 * Total Submissions: 85.8K
 * Testcase Example:  '"324"'
 *
 * Given a nested list of integers represented as a string, implement a parser
 * to deserialize it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Note:
 * You may assume that the string is well-formed:
 * 
 * String is non-empty.
 * String does not contain white spaces.
 * String contains only digits 0-9, [, - ,, ].
 * 
 * 
 * 
 * Example 1:
 * 
 * Given s = "324",
 * 
 * You should return a NestedInteger object which contains a single integer
 * 324.
 * 
 * 
 * 
 * Example 2:
 * 
 * Given s = "[123,[456,[789]]]",
 * 
 * Return a NestedInteger object containing a nested list with 2 elements:
 * 
 * 1. An integer containing value 123.
 * 2. A nested list containing two elements:
 * ⁠   i.  An integer containing value 456.
 * ⁠   ii. A nested list with one element:
 * ⁠        a. An integer containing value 789.
 * 
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
	//Here we consider the stack method.
	//the basic idea is to allocate a new but empty NestedInteger everytime we meet a '['
	//and then add a NestedInteger with numer when we meet , or ']' in different ways
	//start and i is used to determine the number to be added to the top node of the stack
	if(!s.size()) return NestedInteger();
	if(s[0] != '[') return NestedInteger(stoi(s)); //pure number
	if(s.size() <= 2) return NestedInteger();

	stack<NestedInteger> stk;
	int start = 1; 
	for(int i = 0; i < s.size(); i++)
	{
	    if(s[i] == '[') 
	    {
		stk.push(NestedInteger());
		start = i + 1;
	    }

	    if(s[i] == ',' || s[i] == ']')
	    {
		if(i > start)
		{
		    stk.top().add(NestedInteger(stoi(s.substr(start, i - start))));
		}
		start = i + 1;
	    }

	    if(s[i] == ']')
	    {
		if(stk.size() > 1)
		{
		    NestedInteger ni = stk.top();
		    stk.pop(); 
		    stk.top().add(ni);
		}
	    }
	}
	return stk.top();
    }
};













