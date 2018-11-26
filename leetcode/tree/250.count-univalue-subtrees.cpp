/*
 * @lc app=leetcode id=250 lang=cpp
 *
 * [250] Count Univalue Subtrees
 *
 * https://leetcode.com/problems/count-univalue-subtrees/description/
 *
 * algorithms
 * Medium (46.43%)
 * Total Accepted:    29.9K
 * Total Submissions: 64.4K
 * Testcase Example:  '[5,1,5,5,5,null,5]'
 *
 * Given a binary tree, count the number of uni-value subtrees.
 * 
 * A Uni-value subtree means all nodes of the subtree have the same value.
 * 
 * Example :
 * 
 * 
 * Input:  root = [5,1,5,5,5,null,5]
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           1   5
 * ⁠          / \   \
 * ⁠         5   5   5
 * 
 * Output: 4
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
    int countUnivalSubtrees(TreeNode* root) {
	set<TreeNode*> r; //store the roots of single values subtrees
	//post-order traversal and for each access
	//if it is leaf, insert to the set
	//if its left and and right are in the set and has the same value with its own value, insert to the set
	//if only have left or right and it has the same value with its child value, insert to the set
	//why post-order, check the recursive way that it actually needs the childs information firstly
	if(!root) return 0;

	int count = 0;
	stack<TreeNode*> s;
	TreeNode* p = root, *visited = nullptr;
	while(!s.empty() || p)
	{
	    //go to left firstly
	    if(p)
	    {
		s.push(p);
		p = p->left;
	    }
	    else
	    {
		p = s.top();
		if(p->right && p->right != visited) // this p is actually needs to be visited later
		{
		    p = p->right;
		}
		else
		{
		    //visist this node;
		    if((p->right && r.find(p->right) != r.end() && p->left && r.find(p->left) != r.end() && (p->val == p->right->val && p->val == p->left->val)) ||
			(p->right && r.find(p->right) != r.end() && !(p->left) && (p->val == p->right->val)) || 
			(p->left && r.find(p->left) != r.end() && !(p->right) && (p->val == p->left->val))  ||
			(!p->left && !p->right))
		    {
			r.insert(p);
		    }
		    s.pop();
		    visited = p;
		    p = nullptr;
		}
	    }
	}
	return r.size();
    }
};


























