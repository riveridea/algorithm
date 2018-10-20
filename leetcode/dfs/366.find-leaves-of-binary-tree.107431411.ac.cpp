/*
 * [366] Find Leaves of Binary Tree
 *
 * https://leetcode.com/problems/find-leaves-of-binary-tree/description/
 *
 * algorithms
 * Medium (62.49%)
 * Total Accepted:    32.9K
 * Total Submissions: 52.6K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a binary tree, collect a tree's nodes as if you were doing this:
 * Collect and remove all leaves, repeat until the tree is empty.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,4,5]
 * 
 * 1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * Output: [[4,5,3],[2],[1]]
 * 
 * 
 * 
 * 
 * Explanation:
 * 
 * 1. Removing the leaves [4,5,3] would result in this tree:
 * 
 * 
 * ⁠         1
 * ⁠        / 
 * ⁠       2          
 * 
 * 
 * 
 * 
 * 2. Now removing the leaf [2] would result in this tree:
 * 
 * 
 * ⁠         1          
 * 
 * 
 * 
 * 
 * 3. Now removing the leaf [1] would result in the empty tree:
 * 
 * 
 * ⁠         []         
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        //use recursive DFS to solve this problem
        //the key is that the level of the right and left could be different 
        //return the max of right and left
        vector<vector<int> > result;
        dfs(root, result);
        
        return result;
    }

private:
    int dfs(TreeNode *root, vector<vector<int>> &res)
    {
        if (!root) return 0; 
        int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if(level > res.size()) res.push_back(vector<int>());
        res[level - 1].push_back(root->val);
        return level;
    }
};

