/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 *
 * https://leetcode.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (42.81%)
 * Total Accepted:    35.5K
 * Total Submissions: 82.9K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array, your task is to find all the different possible
 * increasing subsequences of the given array, and the length of an increasing
 * subsequence should be at least 2.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [4, 6, 7, 7]
 * Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the given array will not exceed 15.
 * The range of integer in the given array is [-100,100].
 * The given array may contain duplicates, and two equal integers should also
 * be considered as a special case of increasing sequence.
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
	//dfs, and backtracking to find all the answers
	//recursive way
	//dfs(res, curr_res, pos)
	//all the number after current pos are the next nodes
	//after recursion of each next node (if met the condition), 
	//pop back and try another next one,
	//each curr_res at the begining of the dfs are pushed tp res
	//finally return res
    }
};
