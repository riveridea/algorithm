/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (44.04%)
 * Total Accepted:    188.1K
 * Total Submissions: 427.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > results;
        
        if (root == nullptr){
            return results;
        }
        
        queue<TreeNode*> vq; //node queue
        queue<int> dq; //distance queue
        vq.push(root);
        dq.push(0);
        while(!vq.empty()){
            int curr_dist = dq.front();
            TreeNode* curr = vq.front();
            
            if(curr->left){
                vq.push(curr->left);
                dq.push(curr_dist+1);
            }
            if(curr->right){
                vq.push(curr->right);
                dq.push(curr_dist+1);
            }
            
            if (results.size() < curr_dist+1){
                vector<int> level;
                vector<vector<int> >::iterator it;
                it = results.begin();
                results.insert(it,level);
            } 
            
            int value = vq.front()->val;
            results[0].push_back(value);
            dq.pop();
            vq.pop();
        }
        
        return results;        
    }
};
