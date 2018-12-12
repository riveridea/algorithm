/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (29.41%)
 * Total Accepted:    146.4K
 * Total Submissions: 497.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
	//use stack
	//for each prosepctive index i
	//1. pop out the stack if heights[stack[top]] > heights[i]  or heights[stack[top]] == -1
	//   and calcuate the area = (i - stack[top-1] - 1)*heights[stack[top]] and leads to max area
	//2. push the i to the stack
	//when reach the final, i.e., finish the loop, we only have the a increasing heights in the stack
	//pop the stack each time, until -1 is hit, and in the loop to calculate the aren 
	//by area = (heights.length - stack[top-1] - 1) * heights[stack[top]]
	stack<int>  s; //push the index of the element of heights
	s.push(-1);
	int maxarea = 0;

	int m = heights.size();
	cout << m;
	for(int i = 0; i < m; i++)
	{
	    int t = s.top();
	    while(t != -1 && (heights[t] >= heights[i]))
	    {
		s.pop();
		maxarea = max(maxarea, heights[t]*(i - s.top() - 1));	
		t = s.top();
		cout << maxarea;
	    }
	    //cout << i;
	    s.push(i);
	    //cout << s.top();
	}

	//now only the increasing heights stay in the stack
	while(s.top() != -1)
	{
	    int c = s.top();
	    s.pop();
	    maxarea = max(maxarea, heights[c]*(m - s.top() - 1));
	}

	return maxarea;
    }
};
























