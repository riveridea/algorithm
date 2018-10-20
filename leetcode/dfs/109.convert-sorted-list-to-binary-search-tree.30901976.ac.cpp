/*
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (37.74%)
 * Total Accepted:    148.6K
 * Total Submissions: 393.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        //bottom up method 
        //still a recursive way borrowed from the binary search
        //firstly, we need to calculate the length of the list
        ListNode * p = head;
        int len = 0;
        while(p){
            p = p->next;
            len++;
        }
        
        //secondly, call the recursive method to return the 
        //root of the created binary search tree
        //we need the 
        return slist2bst(head, 0, len - 1);
    }
    
    TreeNode* slist2bst(ListNode*& list, int start, int end){
        if (start > end) return nullptr;
        
        int mid = start + (end - start)/2;
        TreeNode* leftchild = slist2bst(list, start, mid-1); //find the middle node and update list
        TreeNode* parent = new TreeNode(list->val);
        parent->left = leftchild;
        list = list->next; //process the right part
        TreeNode* rightchild = slist2bst(list, mid+1, end);
        parent->right = rightchild;
        
        return parent;
    }
};
