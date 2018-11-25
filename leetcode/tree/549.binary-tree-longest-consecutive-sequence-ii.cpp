/*
 * @lc app=leetcode id=549 lang=cpp
 *
 * [549] Binary Tree Longest Consecutive Sequence II
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/description/
 *
 * algorithms
 * Medium (43.15%)
 * Total Accepted:    13K
 * Total Submissions: 30.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a binary tree, you need to find the length of Longest Consecutive Path
 * in Binary Tree. 
 * 
 * Especially, this path can be either increasing or decreasing. For example,
 * [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is
 * not valid. On the other hand, the path can be in the child-Parent-child
 * order, where not necessarily be parent-child order.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * Output: 2
 * Explanation: The longest consecutive path is [1, 2] or [2, 1].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * ⁠       2
 * ⁠      / \
 * ⁠     1   3
 * Output: 3
 * Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 * 
 * 
 * 
 * Note:
 * All the values of tree nodes are in the range of [-1e7, 1e7].
 * ⁠
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
    int longestConsecutive(TreeNode* root) {
	//recursive,
	//for each node, we have a pair<int,int>
	//first --> max len on increasing path
	//second --> max len on decreasing path
	//for each node we need to consider its contact with parent, left child, and right child
	//each recursive returns the pair<int, int> at this node
	//thus we also know the pair<int, int> of its left and right
	//also consider the parent val and current val to determine the parent->node is on a increasing
	//or decreasing path, only on a valid path this node has a non-zero pair of <int, int>
	int res = 0;
	helper(root, root, res);
	return res;
    }

private:
    pair<int, int> helper(TreeNode* node, TreeNode* parent, int& res)
    {
	//stop on the next of leaf
	if(!node) return {0, 0};
	pair<int, int> left = helper(node->left, node, res);
	pair<int, int> right = helper(node->right, node, res);
	//please note, if the child's first and second is not zero, it means the node and child is on
	//the valid path, so we can update based its child's len
	res = max(res, left.first + right.second + 1);
	res = max(res, right.first + left.second + 1);
	//now we update the the node's own first and second based on its relationship with parent
	int inc =0, dec = 0;
	if(node->val - parent->val == 1) //on the increasing path from parent
	{
	    inc = max(left.first, right.first) + 1; //if extending to its child
	}
	if(parent->val - node->val == 1)
	{
	    dec = max(left.second, right.second) + 1; //if extending to its child
	}

	return {inc, dec};
    }
};












