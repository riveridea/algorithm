/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (42.99%)
 * Total Accepted:    229.4K
 * Total Submissions: 530.7K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //use BFS to encode the tree, a preorder traversal
        //iterative stack based implementation
        string res = "";
        if(!root) return res;

        //the stack implementation needs change to handle the null node
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            if(node == NULL){
                res += "null ";
            }
            else{
                q.push(node->left);
                q.push(node->right);
                res += to_string(node->val) + " ";
            }
            q.pop();
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //split the string to vector of string by space
        //using the string stream
        if(!data.size()) return NULL;

        istringstream iss(data);
        vector<string> ds((istream_iterator<string>(iss)),
                           istream_iterator<string>());

        //using the BFS, queue to update the tree, but using the 
        //pointer to pointer to update the node's left and right
        queue<TreeNode**> q;
        TreeNode* root = NULL;
        q.push(&root);
        for(int i = 0; i < ds.size(); i++){
            if(ds[i] != "null") {
                TreeNode** curr = q.front();
                (*curr) = new TreeNode(stoi(ds[i]));
                q.push(&(*curr)->left);
                q.push(&(*curr)->right);
            }
            
            q.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
