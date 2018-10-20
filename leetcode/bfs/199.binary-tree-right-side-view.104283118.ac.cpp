/*
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (44.66%)
 * Total Accepted:    130K
 * Total Submissions: 291K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        //use BFS, output every level of node
        if(root == NULL) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        
        int len = 1;
        while(!q.empty())
        {
            TreeNode* mr = q.front();
            result.push_back(mr->val);
            
            while(len--)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->right) q.push(n->right);
                if(n->left) q.push(n->left);
            }
            len = q.size(); //the current level node number
        }
        
        return result;
    }
};
