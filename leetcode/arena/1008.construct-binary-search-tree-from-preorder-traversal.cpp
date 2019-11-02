/*
 * [1050] Construct Binary Search Tree from Preorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
 *
 * algorithms
 * Medium (73.80%)
 * Total Accepted:    27.6K
 * Total Submissions: 37.3K
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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		//let me exercise the iterative method
		//actually this is a bottom-up solution, we
		//can think about we reach the last tree with a < b < c, 
		//in which a is b's left child and c is b's right child
		//think about it in a pre-order is b, a, c
		//now think about using a stack to store the candidated
		//parent on the top, to compare with the new coming child
		//input from the array preorder
		//we will check, if the top of the stack is less than
		//the new input, this top of the stack should be popped out as
		//a candidated parent(can keep going ahead to check next stack top),
		//if not, this top of the stack should 
		//stay as top but still as the candidate parent
		
		int n = preorder.size();
		if(n == 0) return nullptr;
		stack<TreeNode*> s;
		TreeNode *root = new TreeNode(preorder[0]);
		s.push(root);
		//adding each as child to find its parent
		for(int i = 1; i < n; i++){
			TreeNode *child = new TreeNode(preorder[i]);
			TreeNode *c_parent = s.top();
			//go thru the stack to find the parent
			while(!s.empty()){
				if(s.top()->val < child->val){
					c_parent = s.top();
					s.pop(); // this top coud find now its right
				}
				else{
					break; //this top just got its left
				}
			}
			//connect the parent and child
			if(c_parent->val < child->val)
				c_parent->right = child;
			else
				c_parent->left = child;

			s.push(child); // for cadidated parent of folloing nodes
		}
		return root;
    }
};
