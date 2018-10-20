/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (38.15%)
 * Total Accepted:    177.1K
 * Total Submissions: 464.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end()); //elements in a combination must be in non-descending order
        
        vector<vector<int> > results;
        vector<int> temp_solution;
        
        int new_start = 0;
        int new_target = target;
        
        dfs_build_solution(nums, new_start, new_target, temp_solution, results);
        
        return results;
    }
    
    void dfs_build_solution(vector<int> &nums, int new_start, int new_target, 
                            vector<int> &temp_solution, vector<vector<int> > &results){
        //condition to find the solution
        if(new_target == 0){
            results.push_back(temp_solution);
            return;
        }
        
        //DFS traversal for all the adjacent nodes
        int previous = -1;
        for(int i = new_start; i<nums.size(); i++){
            if (previous == nums[i]) continue; // this is to avoid duplicated solution! not avoid selecting the same value
                                               // as this previous could already generate a solution
            if (nums[i] > new_target) return; //cease the recursion for this path
            
            previous = nums[i]; //
            
            //dfs
            temp_solution.push_back(nums[i]);
            dfs_build_solution(nums, i + 1, new_target - nums[i], temp_solution, results); // i+1 means every item can be used once
            temp_solution.pop_back(); //resume the temp-solution, if solution found within DFS, it is already pushed into the results.
        }
    }
};
