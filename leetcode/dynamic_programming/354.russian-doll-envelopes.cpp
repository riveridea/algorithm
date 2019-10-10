/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (34.45%)
 * Total Accepted:    50.8K
 * Total Submissions: 147.5K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 * 
 * Note:
 * Rotation is not allowed.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3 
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * 
 */
class Solution {
public:
    //define a comaprator for the two vectors
    static bool compare(vector<int>& a, vector<int>& b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //dimension reduction, firstly sort by width to get a array with unsorted height
        //then use the longest increasing subarray to get the answer
        //please note, for two envelopes with the same width, you should get the height 
        //descending, because the ascding heights in this case would not be a solution
        int n = envelopes.size();
        if(!n) return 0;

        sort(envelopes.begin(), envelopes.end(), compare);
        //using dp the solve the LIS problem
        vector<int> f(n,0);
        int global = 0;
        for(int j = 0; j < n; j++){
            f[j] = 1;
            for(int i = 0; i < j; i++){
                //if(envelopes[i][0] < envelopes[j][0] && 
                  if(envelopes[i][1] < envelopes[j][1]){
                    f[j] = max(f[j], f[i] + 1); 
                }
            }
            global = max(global, f[j]);
        }
        return global;
    }
};
