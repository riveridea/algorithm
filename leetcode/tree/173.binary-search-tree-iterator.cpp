/*
 * [173] Binary Search Tree Iterator
 *
 * https://leetcode.com/problems/binary-search-tree-iterator
 *
 * algorithms
 * Medium (42.23%)
 * Total Accepted:    107.2K
 * Total Submissions: 253.5K
 * Testcase Example:  '[]'
 *
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST.
 * 
 * Calling next() will return the next smallest number in the BST.
 * 
 * Note: next() and hasNext() should run in average O(1) time and uses O(h)
 * memory, where h is the height of the tree. 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
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
class BSTIterator {
    stack<TreeNode*> smaller_st;//store the left nodes in the stack
public:
    BSTIterator(TreeNode *root) {
       push_lefts(root); 
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
       return !smaller_st.empty();
    }

    /** @return the next smallest number */
    int next() {
       TreeNode *t = smaller_st.top();
       smaller_st.pop();
       if(t->right != NULL) push_lefts(t->right);

       return t->val; 
    }
private:
    void push_lefts(TreeNode *root)
    {
	TreeNode *p = root;
	while(p != NULL)
	{
	    smaller_st.push(p);
	    p = p->left;
	}
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
