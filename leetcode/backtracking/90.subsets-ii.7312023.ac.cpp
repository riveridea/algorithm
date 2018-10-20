/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (40.01%)
 * Total Accepted:    169.7K
 * Total Submissions: 424K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        //use the incremental construction
        sort(S.begin(), S.end());//must sort 
        vector<vector<int> > result(1); //initilized with an empty subset
        int prev_size = 0;
        for(int i = 0; i< S.size(); i++){
            //save the current size of the result
            int size = result.size();
            for(int j = 0; j<size; j++){
                //i=0 used to initial
                //if new item exists, then combine it
                //if j exceeds the last size, no need to check s[i] and s[i-1]
                if(i == 0 || S[i] != S[i-1] || j >= prev_size){
                    result.push_back(result[j]);
                    result.back().push_back(S[i]);
                }
            }
            prev_size = size;
        }
        return result;
    }
};
