/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (43.82%)
 * Total Accepted:    193.8K
 * Total Submissions: 442.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
	//dfs, but need to use a vector to record the running traversal, in which the last
	//node can compare with the top of stack to determin if all the childs of the last 
	//node has been visted, if yes this last node woule be pop from this vector, which means
	//the backtracing is implemented
	vector<string> paths;
	if(!root) return paths;
	vector<TreeNode*> result;

	stack<TreeNode*> s;
	s.push(root);
	
	while(!s.empty())
	{
	    TreeNode* node = s.top();
	    //s.pop();//
	    TreeNode* last = NULL;
	    if(!result.empty())last = result.back();
	    if(!last || last->left == node || last->right == node) //means the last is the current's parent
	    {
		result.push_back(node); //push back the child
		if(!node->left && !node->right) //hit the leaf
		{
		    string rs;
		    for(auto n : result) 
		    {
			rs += to_string(n->val);	
			if(n != result.back())
			    rs += "->";
		    }
		    paths.push_back(rs);
		}
		//the top of the stack has benn used
		s.pop();  // must pop the stack here as the top isthe child of last
		//push the childs of the curren top
		if(node->left) s.push(node->left);
		if(node->right) s.push(node->right);
	    }
	    else
	    {
		// the last one has no relation to the stack, mush be removed
		result.pop_back();
	    }
	    //you cannot pop the stack here, as here the top could  be child of the next last!
	}
	return paths;
    }
};
