/*
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (32.57%)
 * Total Accepted:    100.7K
 * Total Submissions: 309.1K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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
    void detect(pair<TreeNode*, TreeNode*> &broken, TreeNode* prev, TreeNode* curr){
        if(prev && curr && (prev->val > curr->val)){
            if(broken.first == NULL){
                broken.first = prev;
            }
            broken.second = curr;
        }
    }

    void recoverTree(TreeNode *root) {
        //morris method of inorder traversal
        //if (!root) return;
        
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        pair<TreeNode*, TreeNode*> broken;
        while(curr != NULL){
            if(curr->left == NULL){
                detect(broken, prev, curr);                
                prev = curr;
                curr = curr->right;
            }
            else{
                //find the right most node of the left node of curr
                TreeNode *node = curr->left;
                while(node->right != NULL && node->right != curr){
                    node = node->right;
                }
                
                if(node->right == NULL){
                        node->right = curr;
                        curr = curr->left;
                }
                else{
                    detect(broken, prev, curr);
                    prev = curr;
                    node->right = NULL;
                    curr = curr->right;
                }
            }
		}
		swap(broken.first->val, broken.second->val);
	}
};
