/*
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (56.43%)
 * Total Accepted:    52.1K
 * Total Submissions: 92.4K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * You need to find the largest value in each row of a binary tree.
 * 
 * Example:
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * Output: [1, 3, 9]
 * 
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
    vector<int> largestValues(TreeNode* root) {
	//level ordering traversal
	vector<int> maxs;
	if(!root) return maxs;

	queue<TreeNode*> q;
	q.push(root);
	
	//BFS
	while(!q.empty())
	{
	    int levelsize = q.size(); // the current level size
	    int max_node = INT_MIN;
	    while(levelsize)
	    {
		TreeNode* node = q.front();
		q.pop();
		if(node->left) q.push(node->left);
		if(node->right) q.push(node->right);
		levelsize--;
		max_node = max(max_node, node->val); 	
	    }
	    maxs.push_back(max_node);	
	}
	return maxs;
    }
};
