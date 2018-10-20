/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (36.13%)
 * Total Accepted:    126.1K
 * Total Submissions: 349K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //use the recursive
        //construt the root from the last element of postorder 
        return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
private:
    template<typename BidiIt>
    TreeNode* buildTree(BidiIt in_first, BidiIt in_last, BidiIt post_first, BidiIt post_last){
        if (in_first == in_last || post_first == post_last) return nullptr;
        
        //find the root value firstly to allocate the root node
        auto val = *prev(post_last);
        TreeNode *root = new TreeNode(val);
        
        //compute the left size
        auto in_root_pos = find(in_first, in_last, val);
        auto left_size = distance(in_first, in_root_pos);
        auto post_left_last = next(post_first, left_size);
        
        //recursive to build the left tree and right tree
        root->left = buildTree(in_first, next(in_first, left_size), post_first, post_left_last);
        root->right = buildTree(next(in_root_pos), in_last, post_left_last, prev(post_last));
        
        return root;
    }
};
