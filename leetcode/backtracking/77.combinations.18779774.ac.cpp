/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (43.83%)
 * Total Accepted:    165.6K
 * Total Submissions: 377.9K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        //it is backtracking, but also Depth first searching
        
        vector<vector<int> > result;
        vector<int> path; // for the intermediate result
        
        backtrack(result, path, 1, n, k);
        
        return result;
    }
    
private:
    void backtrack(vector<vector<int> > &result, vector<int> &path, int start, int n,  int k){
        vector<int> candidates;

        if (is_solution(path, k)){
            result.push_back(path);
            return;
        }
        else{
            construct_candidates(candidates, path, start, n); //find all the next candidates
            for(int i = 0; i < candidates.size(); i++){ //here run dfs actually
                path.push_back(candidates[i]); 
                backtrack(result, path, candidates[i] + 1, n, k);
                path.pop_back();
            }
        }
    }
    
    bool is_solution(vector<int> &path, int k){
        return path.size() == k;
    }
    
    void construct_candidates(vector<int> &candidates, vector<int> &path, int start, int n){
        candidates.clear();
        
        for(int i = start; i <= n; i++ ){
                candidates.push_back(i);
        }
    }
};
