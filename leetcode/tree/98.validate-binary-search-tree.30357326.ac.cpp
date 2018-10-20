/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.51%)
 * Total Accepted:    299.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
 * 
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
    bool isValidBST(TreeNode *root) {
        if(!root) return true;
        
    	stack<TreeNode*> S;
        TreeNode* current = root;
        int curr_val, pre_val = INT_MIN;
        int first_compare = 1;
        
        while(!S.empty() || current){
        	if(current){
        		S.push(current);
        		current = current->left;
        	}
        	else{
        		current = S.top();
        		curr_val = current->val;
        		if(curr_val <= pre_val && first_compare == 0){
        		    return false;
        		} 
        		first_compare = 0;
        		pre_val = curr_val;
        		S.pop();
        		current = current->right;
        	}
        }
        return true;
    }

};
