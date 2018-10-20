/*
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (43.37%)
 * Total Accepted:    187.2K
 * Total Submissions: 431.7K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        //dfs, but use a vector to store the temp result 
        //and print this vector everytime when leaf is hit
        if(!root) return {};
        stack<TreeNode*> s;
        s.push(root);
        
        vector<string> result;
        vector<TreeNode*> rc;
        while(!s.empty())
        {
            TreeNode* n = s.top();
            TreeNode* last = NULL;
            
            if(!rc.empty()) last = rc.back();
            if(!last || last->right == n || last->left == n)
            {
                rc.push_back(n);
                if(!n->left && !n->right)
                {
                    //this is leaf
                    //determine if it is the time to add the result

                    //add to the result
                    string rs;
                    for(auto node : rc)
                    {
                        rs += to_string(node->val);
                        if(node != rc.back())
                            rs += "->";
                    }
                    result.push_back(rs);
                }
                s.pop();
                if(n->left) s.push(n->left);
                if(n->right) s.push(n->right);
            }
            else
            {
                rc.pop_back();
            }
        }
        return result;
    }
};
