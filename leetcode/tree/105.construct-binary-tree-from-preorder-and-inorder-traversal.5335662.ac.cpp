/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (37.12%)
 * Total Accepted:    172K
 * Total Submissions: 463.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeImpl(begin(preorder),end(preorder),
                             begin(inorder),end(inorder));
    }
    
    //use the four iterator functions
    //find(), distance(), begin(), end()
    //template<typename InputIterator>
    TreeNode* buildTreeImpl(vector<int>::iterator  pre_first, vector<int>::iterator  pre_last, 
                            vector<int>::iterator  in_first,  vector<int>::iterator  in_last){
        if(pre_first == pre_last) return nullptr;
        if(in_first == in_last) return nullptr;
        
        //construct the root node
        auto root = new TreeNode(*pre_first);
        //find the location of the root node in in-order vector
        auto inRootPos = find(in_first, in_last, *pre_first);
        auto leftSize = distance(in_first, inRootPos);
        
        //Build the left and right tree
        //Note: next(first, offset), shift from first with offset, default offset = 1
        TreeNode *left_root = buildTreeImpl(next(pre_first), next(pre_first, leftSize+1),
                                            in_first, inRootPos);
        TreeNode *right_root =buildTreeImpl(next(pre_first, leftSize+1), pre_last,
                                            next(inRootPos), in_last);
        //connect the root with left and right tree
        root->left = left_root;
        root->right = right_root;
        
        return root;
    }
};
