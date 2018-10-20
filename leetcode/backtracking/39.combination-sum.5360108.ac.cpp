/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (44.10%)
 * Total Accepted:    261.4K
 * Total Submissions: 592.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        
        vector<int> intermeidate;
        dfs(candidates, target, 0, intermeidate, result);
        return result;
    }
    
    void dfs(vector<int> &candidates, int target, int start, vector<int> &intermeidate, vector<vector<int> > &result){
        if(target == 0){//find a valid solution
            result.push_back(intermeidate);
            return;
        }
        
        int previous = -1;
        for(int i=start; i<candidates.size(); i++){
            if (previous == candidates[i]) continue; //avoid the duplicated solution
            if(candidates[i] > target) return; //ignore the element greater than target
            
            previous = candidates[i];
            intermeidate.push_back(candidates[i]);
            //elements smaller than candiates[i] will not be inserted as the solution is non-descending
            dfs(candidates, target - candidates[i], i, intermeidate, result);
            intermeidate.pop_back(); //cancel the previous operation for new solution
        }
    }
}; 
