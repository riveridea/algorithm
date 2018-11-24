/*
 * @lc app=leetcode id=298 lang=cpp
 *
 * [298] Binary Tree Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (42.77%)
 * Total Accepted:    53.5K
 * Total Submissions: 125.1K
 * Testcase Example:  '[1,null,3,2,4,null,null,null,5]'
 *
 * Given a binary tree, find the length of the longest consecutive sequence
 * path.
 * 
 * The path refers to any sequence of nodes from some starting node to any node
 * in the tree along the parent-child connections. The longest consecutive path
 * need to be from parent to child (cannot be the reverse).
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   / \
 * ⁠  2   4
 * ⁠       \
 * ⁠        5
 * 
 * Output: 3
 * 
 * Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 
 * ⁠  2
 * ⁠   \
 * ⁠    3
 * ⁠   / 
 * ⁠  2    
 * ⁠ / 
 * ⁠1
 * 
 * Output: 2 
 * 
 * Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return
 * 2.
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
	//actually we need to go through all the paths and find the longest consecutive sequence path
	if(!root) return 0;
	vector<int> lens;
	vector<pair<TreeNode*, int>>  trace;
	stack<TreeNode*> s;
	s.push(root);
	int maxlen = 1;
	pair<TreeNode*, int> last(NULL, 0);
	while(!s.empty())
	{
	    TreeNode* current = s.top();
	    if(!trace.empty()) 
	    {
		last = trace.back();
	    }
	    if(!last.first || last.first->left == current || last.first->right == current)
	    {
		pair<TreeNode*, int> current_trace(current, 1);
		int diff = 0;
		if(last.first != NULL)
		{ 
		    diff = current->val - last.first->val;
		}
		if(diff == 1)
		{
		    current_trace.second = last.second+1; 
		}
		else
		{
		    current_trace.second = 1;
		}
		
		//push to trace after everyting updated
		trace.push_back(current_trace);
		maxlen = max(maxlen, current_trace.second);

		s.pop();
		if(current->left) s.push(current->left);
		if(current->right) s.push(current->right);
	    }
	    else
	    {
		trace.pop_back();
	    }
	}
    
	return maxlen;
    }
};
