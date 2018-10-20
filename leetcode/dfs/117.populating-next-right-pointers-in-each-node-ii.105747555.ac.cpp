/*
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (33.46%)
 * Total Accepted:    152.2K
 * Total Submissions: 454.9K
 * Testcase Example:  '{}'
 *
 * Given a binary tree
 * 
 * 
 * struct TreeLinkNode {
 * ⁠ TreeLinkNode *left;
 * ⁠ TreeLinkNode *right;
 * ⁠ TreeLinkNode *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * Note:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 * 
 * 
 * Example:
 * 
 * Given the following binary tree,
 * 
 * 
 * ⁠    1
 * ⁠  /  \
 * ⁠ 2    3
 * ⁠/ \    \
 * 4   5    7
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * 
 * ⁠    1 -> NULL
 * ⁠  /  \
 * ⁠ 2 -> 3 -> NULL
 * ⁠/ \    \
 * 4-> 5 -> 7 -> NULL
 * 
 * 
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //use BFS, update each level by now pointer, then set the head 
        //tail is used to travel to the right most 
        //cannot use stack as O(1) space is required
        TreeLinkNode *now = root;
        TreeLinkNode *head, *tail;
        head = tail = NULL;
        
        while(now){
            if(now->left)
            {
                if(tail)
                {
                    //move tail to next
                    tail->next = now->left;
                    tail = tail->next;
                }
                else
                {
                    //tail is null means still stay in the left most
                    tail = now->left;
                    head = tail;
                }
            }
            
            if(now->right)
            {
                if(tail)
                {
                    //move tail to next
                    tail->next = now->right;
                    tail = tail->next;
                }
                else
                {
                    tail = now->right;
                    head = tail;
                }
            }
            
            //to if move now to the next level
            now = now->next;
            if(!now)//no next for current next, means need to go to next level
            {
                now = head; //start from the left most for next level
                head = tail = NULL;
            }
        }
    }
};
