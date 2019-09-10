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
	vector<vector<int>> res;
	vector<int> curr_res;

	n = nums.size();
	dfs(res, curr_res, nums, 0);
	return res;
    }
private:
    int n;
    void dfs(vector<vector<int>>& res, vector<int>& curr_res, vector<int>& nums, int pos){
	if(curr_res.size() > 1) res.push_back(curr_res);
	
	unordered_set<int> hash;
	for(int i = pos; i < n; i++){
	    if((curr_res.empty() || nums[i] >= curr_res.back()) && hash.find(nums[i]) == hash.end()){
		curr_res.push_back(nums[i]);
		dfs(res, curr_res, nums, i+1);
		curr_res.pop_back();
		hash.insert(nums[i]);
	    }    
	}
    }
};


















