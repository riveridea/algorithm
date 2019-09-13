/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (63.88%)
 * Total Accepted:    55.1K
 * Total Submissions: 86.3K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree.  From left to right order, the
 * values of those leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Both of the given trees will have between 1 and 100 nodes.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	//do the dfs for each tree together and compare during the dfs 
	//iterative, actually do the iterative dfs together
	stack<TreeNode*> s1, s2;
	s1.push(root1);
	s2.push(root2);
	while(!s1.empty() && !s2.empty()){
	    if(dfs(s1) != dfs(s2)) return false;
	}
    
	return s1.empty() && s2.empty();
    }
private:
    int dfs(stack<TreeNode*>& s){
	while(1){
	    TreeNode* p = s.top(); s.pop();
	    if(p->left) s.push(p->left);
	    if(p->right) s.push(p->right);
	    if(!p->left && !p->right) return p->val;
	}
    }
};

































