/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (49.61%)
 * Total Accepted:    42K
 * Total Submissions: 84.7K
 * Testcase Example:  '[[1,2], [2,3], [3,4]]'
 *
 * 
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 * 
 * 
 * 
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
 * < c. Chain of pairs can be formed in this fashion. 
 * 
 * 
 * 
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The number of given pairs will be in the range [1, 1000].
 * 
 * 
 */
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]); 
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        //sort by b and then  do the greedy, need to find why greedy works
        int n = pairs.size();
        if(!n) return 0;

        sort(pairs.begin(), pairs.end(), compare);
        //greedy
        int global = 1;
        int tail = pairs[0][1];
        for(int i = 1; i < n; i++){
            if(pairs[i][0] > tail){
                tail = pairs[i][1];
                global++;
            }
        }
        return global;
    }
};
