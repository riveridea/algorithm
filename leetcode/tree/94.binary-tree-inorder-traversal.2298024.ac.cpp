/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (52.70%)
 * Total Accepted:    348K
 * Total Submissions: 660.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        
        //if(!root) return result;
        
        stack<TreeNode*> s;
        
        TreeNode* current = root;
        //s.push(root);
        while(!s.empty() || current){
            //if(current->left){ //Can not use this way, as the current could be null or current->left coule be already visited
            if(current){
                s.push(current);
                //s.push(current->left);
                current = current->left;
            }
            else{
                current = s.top();
                result.push_back(current->val);
                s.pop();
                current = current->right;
                //if(current) s.push(current);
            }
        }
        return result;
    }
};
