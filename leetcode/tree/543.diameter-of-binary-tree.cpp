/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.38%)
 * Total Accepted:    169.7K
 * Total Submissions: 356.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
    int diameterOfBinaryTree(TreeNode* root) {
        //l + r + 1
        if(!root) return 0;

        //iterative post-order + memo
        int mx = 0;
        unordered_map<TreeNode*, int> d;
        stack<TreeNode*> s;
        TreeNode *n = root;
        while(n || !s.empty()){
            if(n){
                s.push(n);
                n = n->left;
            }
            else{
                n = s.top();
                if(n->right && d.find(n->right) == d.end()){
                    n = n->right;
                }
                else{
                    //n's left and right all being processed
                    int l = d[n->left], r = d[n->right];
                    d[n] = max(l, r) + 1;
                    s.pop();
                    mx = max(mx, l+r);
                    n = NULL;
                }
            }
        }
        return mx;
    }
};
