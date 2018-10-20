/*
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (38.71%)
 * Total Accepted:    167.4K
 * Total Submissions: 432.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        //Bread First Searching:
        //Iterative way is using a Queue, first in first out
        //Use a nullptr to separate the level
        vector<vector<int> > result;
        if(root == nullptr) return result;
        vector<int> level; //store every level nodes
        
        queue<TreeNode*> q; //queue 
        bool left_to_right = true;
        
        q.push(root);
        q.push(nullptr); //nullptr as level separator
        
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            
            if(cur){//no level end reaches
                level.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            else{//level separator met
                if(left_to_right){
                    result.push_back(level);
                }
                else{
                    reverse(level.begin(), level.end());
                    result.push_back(level);
                }
                
                level.clear();
                left_to_right = !left_to_right; //don't forget to reverse!
                if(q.size() > 0) q.push(nullptr);
            }
        }
        
        return result;
    }
};
