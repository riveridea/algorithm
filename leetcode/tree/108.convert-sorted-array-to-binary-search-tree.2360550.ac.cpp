/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (46.99%)
 * Total Accepted:    207.2K
 * Total Submissions: 440.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return nullptr;
        
        return sortA2Bst(num, 0, num.size()-1);
    }
private:
    TreeNode *sortA2Bst(vector<int> &num, int start, int end){
        if (start > end) return nullptr;

        int mid = start + (end - start)/2;
        TreeNode * root = new TreeNode(num[mid]);
        TreeNode * left = sortA2Bst(num, start, mid-1);
        TreeNode * right = sortA2Bst(num, mid+1, end);
        root->left = left;
        root->right = right;
        
        return root;
    }
};
