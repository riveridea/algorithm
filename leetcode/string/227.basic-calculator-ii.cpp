/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (31.97%)
 * Total Accepted:    88.6K
 * Total Submissions: 277.1K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 * 
 * Example 1:
 * 
 * 
 * Input: "3+2*2"
 * Output: 7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: " 3/2 "
 * Output: 1
 * 
 * Example 3:
 * 
 * 
 * Input: " 3+5 / 2 "
 * Output: 5
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 * 
 */
class Solution {
public:
    int calculate(string s) {
	//use a stack to record each number that could be used for 
	//next step of calcualting
	//every time we meet an operator, we check the previous operator
	//to decide how to use the current top of the stack
	stack<int> st;
	int n = s.size();

	int num = 0;
	char op = '+';
	for(int i = 0; i < n; i++)
	{
	    if(s[i] >= '0') 
		num = num*10 + s[i] - '0'; //num will be reset to 0 once an operator is processed
	    
	    if(s[i] < '0' && s[i] != ' ' || i == n-1)
	    {
		int temp = 0;
		switch(op) {
		    case '+':  st.push(num); break; //the previous operator is +
		    case '-':  st.push(-num); break; 
		    case '*':
			//update the num
			temp = st.top()*num;
			st.pop();
			st.push(temp);
			break;
		    case '/':
			//update the num
			temp = st.top()/num;
			st.pop();
			st.push(temp);
			break;
		    default:
			break;
		}	
		//update op
		op = s[i];
		num = 0; //reset the num
	    }
	}

	int res = 0;
	while(!st.empty())
	{
	    cout << st.top();
	    res += st.top();
	    st.pop();
	}

	return res;
    }
};
