/*
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (48.78%)
 * Total Accepted:    269.7K
 * Total Submissions: 552.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;
        
        while(current){
            result.push_back(current->val);
            if(current->left && current->right){ 
                s.push(current); //to record the node with left and right 
                                 //thus the left leave travers to right
            }
            
            if(current->left){ 
                current = current->left;
            }
            else if(current->right){
                current = current->right;
            }
            else if(!s.empty()){//left leaf, to find the right leaf
                current = s.top()->right;
                s.pop();
            }
            else{
                current = nullptr;
            }
        }
        
        return result;
    }
};
