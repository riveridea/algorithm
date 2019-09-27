/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (73.52%)
 * Total Accepted:    24.1K
 * Total Submissions: 32.8K
 * Testcase Example:  '[8,5,1,7,10,12]'
 *
 * Return the root node of a binary search tree that matches the given preorder
 * traversal.
 * 
 * (Recall that a binary search tree is a binary tree where for every node, any
 * descendant of node.left has a value < node.val, and any descendant of
 * node.right has a value > node.val.  Also recall that a preorder traversal
 * displays the value of the node first, then traverses node.left, then
 * traverses node.right.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [8,5,1,7,10,12]
 * Output: [8,5,10,1,7,null,12]
 * 
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= preorder.length <= 100
 * The values of preorder are distinct.
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
    int idx;
    int n;
public:
    TreeNode* create_stree(int low, int upper, vector<int>& preorder){
	if(idx == n)  return NULL;
	int val = preorder[idx];
	if(val < low || val > upper) return NULL;

	idx++;
	TreeNode* root = new TreeNode(val);
	root->left = create_stree(low, val, preorder);
	root->right = create_stree(val, upper, preorder);

	return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
	//try recursive firstly
	//use the low_limit and upper_limit to check if the current node can be 
	//placed to the subtree
	if(preorder.empty()) return NULL;

	idx = 0;
	n = preorder.size();
	return create_stree(INT_MIN, INT_MAX, preorder);
    }
};
