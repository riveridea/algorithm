/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.29%)
 * Total Accepted:    73.9K
 * Total Submissions: 166.8K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
	//try the DFS, think about a binary tree started from 0
	//every node will have two childs, in which the +b and -b
	int m = nums.size();
	if(m == 0) return 0;

	int ways = 0;
	int sum = 0, level = 0;
	stack<int> q;
	q.push(0) // start from 0
	while(!q.empty())
	{
	    int a = q.top();
	    sum += sum;
	    level++;
	    if(level == m && sum == S){
		ways++;
		level--;
	    }
	}
    }
};
















