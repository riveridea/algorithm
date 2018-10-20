/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (50.64%)
 * Total Accepted:    255.4K
 * Total Submissions: 504.4K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>(1, "");
        if (n == 1) return vector<string>(1, "()");
        
        vector<string> result;
        for(int i=0; i<n; i++){
            for (auto inner: generateParenthesis(i)){
                for (auto outer: generateParenthesis(n-i-1)){
                    result.push_back("(" + inner + ")" + outer);
                }
            }
        }
        return result;
    }
};
