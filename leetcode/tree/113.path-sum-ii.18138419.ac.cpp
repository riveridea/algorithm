/*
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (37.77%)
 * Total Accepted:    190.7K
 * Total Submissions: 504.9K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        //Depth first search, but need to record the intermediate result
        vector<vector<int>> result;
        vector<int> cur; //store the result in one search
        pathSumUtil(root, sum, cur, result);
        return result;
    }
private:
    void pathSumUtil(TreeNode *root, int gap, vector<int> &cur, vector<vector<int>> &result){
        if(root == nullptr) return;
        
        cur.push_back(root->val);
        //check if leaf node
        if(root->left == nullptr && root->right == nullptr){
            if(gap == root->val){
                result.push_back(cur);
            }
        }
        // continue search the adjacent nodes(left and right node if exist)
        pathSumUtil(root->left, gap - root->val, cur, result);
        pathSumUtil(root->right, gap - root->val, cur, result);
        
        //don't forget pop out the recent cur
        cur.pop_back();
    }
};
