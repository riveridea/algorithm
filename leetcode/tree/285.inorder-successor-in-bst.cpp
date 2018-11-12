/*
 * [285] Inorder Successor in BST
 *
 * https://leetcode.com/problems/inorder-successor-in-bst/description/
 *
 * algorithms
 * Medium (33.29%)
 * Total Accepted:    80.6K
 * Total Submissions: 242.2K
 * Testcase Example:  '[0]\nnode with value 0'
 *
 * Given a binary search tree and a node in it, find the in-order successor of
 * that node in the BST.
 * 
 * Note: If the given node has no in-order successor in the tree, return null.
 * 
 * Example 1:
 * 
 * 
 * Input: root = [2,1,3], p = 1
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   3
 * 
 * Output: 2
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], p = 6
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   3   6
 * ⁠  / \
 * ⁠ 2   4
 * ⁠/   
 * 1
 * 
 * Output: null
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
	//need to use the property of BST
	//to implement O(lgn)
	//the successor of p must be greater than p
	//keep upating root
	//if p is in the left of root, then root must be after or equal to the successor of p,
	//then set root as a candicate of successor, and continue find the successor on the left of root
	//if p is in the right of root, then root must not be after or equal to the succesor of p
	//then we need to continue to find the success in the right of root, but not update successor
	if(!root || !p) return NULL;
	TreeNode *suc = NULL;

	while(root != NULL)
	{
	    if(root->val <= p->val)
	    {
		//p is on the right of root
		root = root->right;
	    }
	    else
	    {
		suc = root; //cache root as a candidate
		root = root->left; //continue check left of root 
	    }
	}

	return suc;
    }
};
