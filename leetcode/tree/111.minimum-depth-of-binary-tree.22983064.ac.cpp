/*
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (34.18%)
 * Total Accepted:    246.2K
 * Total Submissions: 720.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
    int minDepth(TreeNode *root) {
        //Notes:
        //1. bread first search, dont forget how to write BFS!!, Queue, and while(Q.empty)!
        //2. depth is obtained when leaf node is reached
        //3. update the right most only when the curr is rightMost 
        //4. if current right most has no right node, then curr's left is righ most
        //5. if right most is used, then curr->left should be insert firstly
        if(root == nullptr) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* rightMost = root;
        int level = 1;
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left == nullptr && curr->right == nullptr) 
                break; // a leaf is found, level is the current value
       
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);    
            
            //decide if right most node is reached and upate the rightmost
            if(curr == rightMost){
                //now increment the depth and updat the rightmost
                level++; //because we at least are not leaf, so adding one
                rightMost = (curr->right != nullptr)?curr->right: curr->left;
            }
        }
        
        return level;
    }
};
