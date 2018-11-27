/*
 * @lc app=leetcode id=333 lang=cpp
 *
 * [333] Largest BST Subtree
 *
 * https://leetcode.com/problems/largest-bst-subtree/description/
 *
 * algorithms
 * Medium (31.79%)
 * Total Accepted:    25.1K
 * Total Submissions: 79K
 * Testcase Example:  '[10,5,15,1,8,null,7]'
 *
 * Given a binary tree, find the largest subtree which is a Binary Search Tree
 * (BST), where largest means subtree with largest number of nodes in it.
 * 
 * Note:
 * A subtree must include all of its descendants.
 * 
 * Example:
 * 
 * 
 * Input: [10,5,15,1,8,null,7]
 * 
 * ⁠  10 
 * ⁠  / \ 
 * ⁠ 5  15 
 * ⁠/ \   \ 
 * 1   8   7
 * 
 * Output: 3
 * Explanation: The Largest BST Subtree in this case is the highlighted one.
 * ⁠            The return value is the subtree's size, which is 3.
 * 
 * 
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        isValidBST(root, mn, mx, res);
        return res;
    }
    void isValidBST(TreeNode *root, int &mn, int &mx, int &res) {
        if (!root) return;
        int left_n = 0, right_n = 0, left_mn = INT_MIN;
        int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
        isValidBST(root->left, left_mn, left_mx, left_n);  //actually we don't need return if or not the left subtree is BST or not
        isValidBST(root->right, right_mn, right_mx, right_n); //if child BST, no problem, the child's size is 0 and the child's max/min are INT_MIN/INT_MAX
        if ((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)) { //so here it is enough
            res = left_n + right_n + 1;
            mn = root->left ? left_mn : root->val;
            mx = root->right ? right_mx : root->val;
        } else res = max(left_n, right_n);
    }
}; 
