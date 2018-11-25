/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (41.82%)
 * Total Accepted:    25.9K
 * Total Submissions: 61.8K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given a binary tree, return all duplicate subtrees. For each kind of
 * duplicate subtrees, you only need to return the root node of any one of
 * them.
 * 
 * Two trees are duplicate if they have the same structure with same node
 * values.
 * 
 * Example 1: 
 * 
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   2   4
 * ⁠      /
 * ⁠     4
 * 
 * 
 * The following are two duplicate subtrees:
 * 
 * 
 * ⁠     2
 * ⁠    /
 * ⁠   4
 * 
 * 
 * and
 * 
 * 
 * ⁠   4
 * 
 * Therefore, you need to return above trees' root in the form of a list.
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
	//serilization of the tree to a string and use this string to check duplicates
	vector<TreeNode*> result; //store the root of substree of duplicates
	unordered_map<string, int> m;
	helper(root, m, result);
	return result;
    }
private:
    string helper(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& res)
    {
	if(node == NULL)  return "#";
	string str = to_string(node->val) + "," + helper(node->left, m, res) + helper(node->right, m, res);
	if(m[str] == 1) res.push_back(node); // duplicate found, but only once is pushed
	m[str]++;
	return str;
    }

};















