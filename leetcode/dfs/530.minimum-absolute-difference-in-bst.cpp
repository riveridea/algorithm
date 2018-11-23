/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (48.69%)
 * Total Accepted:    48K
 * Total Submissions: 98.6K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note: There are at least two nodes in this BST.
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
    int getMinimumDifference(TreeNode* root) {
	//this is actually an in-order traversal of BST, as the in-order traversal 
	//is going to generate a sorted queue
	//let's try the iterative DFS 
	//iterative DFS for inorder, needs to go to the left most firstly (push to stack during the process)
	//if left is ended then go to right until leaf then pop
	if(!root) return 0;
	stack<TreeNode*> s;
	TreeNode* current = root;
	vector<int> sorted;
	while(!s.empty() || current != NULL)  //if s is empty, current must be non-null
	{
	    if(current)
	    {
		s.push(current);
		current = current->left;
	    }
	    else
	    {
		current = s.top();
		sorted.push_back(current->val);
		s.pop(); //last current is null means the the null's parent is a middle
		current = current->right;
	    }
	}
	
	if(sorted.size() <= 1) return 0;
	int mindiff = INT_MAX;
	for(int i = 1; i < sorted.size(); i++)	
	{
	    mindiff = min(mindiff, abs(sorted[i] - sorted[i-1])); 
	}
	return mindiff;
    }
};
