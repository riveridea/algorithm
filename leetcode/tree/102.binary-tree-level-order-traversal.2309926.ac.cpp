/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.06%)
 * Total Accepted:    288.5K
 * Total Submissions: 640.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        
        if(!root) return result;
        
        queue<TreeNode*> current, prev;
        current.push(root);
        
        while(!current.empty()){
            vector<int> level;
            
            while(!current.empty()){
                TreeNode* p = current.front();
                
                if(p->left) prev.push(p->left);
                if(p->right) prev.push(p->right);
                
                level.push_back(p->val);
                current.pop();
            }
            
            result.push_back(level);
            swap(prev, current);
        }
        return result;
    }
};
