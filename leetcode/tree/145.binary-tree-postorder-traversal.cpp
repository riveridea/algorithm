/*
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (44.84%)
 * Total Accepted:    209K
 * Total Submissions: 466K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        //use stack to implement the post-order traversal
        //to implement this,  you thinking is divided to two steps：
        //1. natural figure out the stack sequnce
        //2. fix the problem that the root is checked second time in stack peek,
        // how to determine go back the root of the last level root
        
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode* > s;
        TreeNode* node = root, *visited_node = nullptr;
        //TreeNode* peaknode;
        
        //s.push(node);
        while(!s.empty() || node != nullptr){
            if(node != nullptr){
                s.push(node);
                node = node->left;
            }
            else{
                node = s.top();
                if(node->right && node->right != visited_node){
                    node = node->right;
                }
                else{
                    result.push_back(node->val);
                    s.pop();
                    visited_node = node;
                    node = nullptr;
                }
            }
        }
        return result;
    }
};
