/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (38.33%)
 * Total Accepted:    49K
 * Total Submissions: 127.7K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 * 
 * Basically, the deletion can be divided into two stages:
 * 
 * Search for a node to remove.
 * If the node is found, delete the node.
 * 
 * 
 * 
 * Note: Time complexity should be O(height of tree).
 * 
 * Example:
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Given key to delete is 3. So we find the node with value 3 and delete it.
 * 
 * One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * Another valid answer is [5,2,6,null,4,null,7].
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
	//use iterative way, we need a helper function in which the input parameter is the 
	//node to be deleted and reture a subtree root after deletion and assign this root to the node's parent
	//two cases: if the node to be delted is the root of the total tree, call helper directly
	//if not keep binary search until the target node is found and call helper 
	//when deleting the node, we just need to find the right most node of left tree of the node, and assign
	//the right child of the node to the right most node the left tree of the node.
	if(!root) return nullptr;

	if(root->val == key) return delete_root(root);

	TreeNode* rc = root;
	//start binary search
	while(rc)
	{
	    if(key < rc->val)
	    {
		if(rc->left && rc->left->val == key)
		{
		    //re->left is to be deleted
		    rc->left = delete_root(rc->left); //deleted the rc->left and return a new subtree root as left child
		}
		else
		{
		    rc = rc->left; // key is on the left tree
		}
	    }
	    else
	    {
		if(rc->right && rc->right->val == key)
		{
		    //rc->right is to be deleted
		    rc->right = delete_root(rc->right); //deleted the rc->right and return a new subtree root as right child
		}
		else
		{
		    rc = rc->right;
		}
	    }
	}
	return root;
    }
private:
    TreeNode* delete_root(TreeNode* root)
    {
	//if root is leaf, just delete it
	//if it has no left node, just return the right child and delete it
	//if it has no right node, just return the left child and delete it
	//if it has both, need to traverse to the right most one and connect it with the root's right child
	TreeNode* newtree = nullptr;
	if(!root->left && !root->right)
	{
	    delete root;
	}
	else if(!root->left)
	{
	    newtree = root->right;
	    delete root;
	}
	else if(!root->right)
	{
	    newtree = root->left;
	    delete root;
	}
	else
	{
	    //find the right most of the left subtree
	    TreeNode* rightmost_ltree = root->left;
	    //cout << "rm:" << rightmost_ltree->val;
	    while(rightmost_ltree->right)
	    {
		rightmost_ltree = rightmost_ltree->right;
		//cout << "irm:" << rightmost_ltree->val;
	    }
	    //connect the right most of the left tree with the right child of the root
	    rightmost_ltree->right = root->right;
	    newtree = root->left;
	    delete root;
	}
	return newtree; //we got a new BST tree 
    }
};
