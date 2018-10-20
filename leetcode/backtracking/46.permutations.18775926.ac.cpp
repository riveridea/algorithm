/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (50.61%)
 * Total Accepted:    289K
 * Total Submissions: 571K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        //it is backtracking, but also Depth first searching
        vector<vector<int> > result;
        vector<int> path; // for the intermediate result
        
        backtrack(result, path, num);
        
        return result;
    }
    
private:
    void backtrack(vector<vector<int> > &result, vector<int> &path, vector<int> &num){
        vector<int> candidates;
        
        if (is_solution(path, num)){
            result.push_back(path);
            return;
        }
        else{
            construct_candidates(candidates, path, num); //find all the next candidates
            for(int i = 0; i < candidates.size(); i++){ //here run dfs actually
                path.push_back(candidates[i]); 
                backtrack(result, path, num);
                path.pop_back();
            }
        }
    }
    
    bool is_solution(vector<int> &path, vector<int> &num){
        return path.size() == num.size();
    }
    
    void construct_candidates(vector<int> &candidates, vector<int> &path, vector<int> &num){
        candidates.clear();
        
        for(auto i:num){
            auto pos = find(path.begin(), path.end(), i); // elements already in the path will not be as candidates
            
            if(pos == path.end()){//find one next candidate
                candidates.push_back(i);
            }
        }
    }
};
