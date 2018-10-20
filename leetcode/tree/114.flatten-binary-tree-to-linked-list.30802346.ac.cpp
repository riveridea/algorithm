/*
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (38.95%)
 * Total Accepted:    193.4K
 * Total Submissions: 496.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten(TreeNode* root) {
        //this is pre-order application
        stack<TreeNode* > s;
        TreeNode* p = root;
        TreeNode* parent = nullptr;
        
        if(p != nullptr) s.push(p);
        while(!s.empty()){
            p = s.top();
            s.pop();
            
            if(parent != nullptr){
                parent->right = p;
                parent->left = nullptr;
            }
            parent = p;
            
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
        }
    }
};
