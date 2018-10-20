/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (48.21%)
 * Total Accepted:    285.1K
 * Total Submissions: 591.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        //use bitmap 
        //suppose we have {a, b, c, d}, the length is 4, thus we have
        //possible representation from 0000 to 1111
        
        //sort firstly
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> v;
        
        int n = S.size();
        for(int i = 0; i < 1<<n; i++){
            for(int j = 0; j<n; j++){
                if(i & 1<<j) v.push_back(S[j]);
            }
            result.push_back(v);
            v.clear();
        }
        return result;
    }
};
