/*
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (43.54%)
 * Total Accepted:    167.9K
 * Total Submissions: 385.6K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
class Solution {
public:
    int numTrees(int n) {
        //1-dimension DP problem
        // for the root, the trees number is the multiplication of the left subtree number and the right subtree number
        // f[i] = sum f[k-1]*f[i-k] k = 1...i
        
        int f[n+1];
        
        f[0] = 1;
        f[1] = 1;
        
        for(int i = 2; i < n + 1; i++){
            f[i] = 0;
            for(int k = 1; k < i+1 ; k++){
                f[i] += f[k-1]*f[i-k];
            }
        }
        
        return f[n];
    }
};
