/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (37.92%)
 * Total Accepted:    203.8K
 * Total Submissions: 537.3K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
	//let us try the recursive firstly
	//firstly sort the nums.
	//suppose the current candicates of nums is
	//i, i+1, ...., j
	//in the dfs(i, j) we call the next possible states:
	//dfs(i+1, j) to form all the possible permutaitons with the
	//i is fixed. then update i to swap to a possbiile value in [i+1, j], named nums[k]
	//except the nums[k] == nums[i]
	//the stop point of the dfs is when i == j, means only 1 is left, i.e., only one permuatation
	vector<vector<int>> result;
	if(nums.empty()) return result;
	int n = nums.size();

	sort(nums.begin(), nums.end());
	dfs(nums, 0, n-1, result);
	return result;
    }
private:
    void dfs(vector<int>& nums, int i, int j, vector<vector<int>>& res)
    {
	//stop conidtions;
	if(i == j)
	{
	    res.push_back(nums);
	    return;
	}

	for(int k = i; k <= j; k++)
	{
	    //here, you understand that only sorting can ensure avoding duplicates!
	    if(k > i && nums[k]==nums[i]) continue; //duplicates, no need to recurse
	    //try different next state
	    swap(nums[i], nums[k]);
	    dfs(nums, i+1, j, res);
	}

	//resume the nums
	for(int l = nums.size() - 1; l > i; l--)
	{
	    swap(nums[l], nums[i]);
	}
    }

    void swap(int& a, int& b) 
    {
	int temp = a;
	a = b;
	b = temp;
    }
};




















