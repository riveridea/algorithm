/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (44.69%)
 * Total Accepted:    43.5K
 * Total Submissions: 97.3K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree
 * structure.
 * 
 * The encoded string should be as compact as possible.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
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
	//preorder traversal of a BST will generate such a serilized structure:
	//5 [2 1 4] [6 8]
	//thus the deserialize can use a queue to recursively reconstruct the BST
	//using the BST properties, the val of the root is greater than left leaf and 
	//smaller than its right
	
	//iterative pre-order
	string result = "";
	stack<TreeNode*> s;
	TreeNode* current = root;
	while(current)
	{
	    result.append(reinterpret_cast<const char*>(&current->val), sizeof(current->val));
	    if(current->left && current->right)
	    {
		s.push(current);
	    }
	    
	    if(current->left)
		current = current->left;
	    else if(current->right)
		current = current->right;
	    else if(!s.empty())
	    {
		current = s.top()->right;
		s.pop();
	    }
	    else
		current = nullptr;
	}
	return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       //firstly we try deserialize in recursion
       int pos = 0;
       return deserialize(data, pos, INT_MIN, INT_MAX);
    }

    //pos must be passed in reference, thus it can keep going ahead
    TreeNode* deserialize(const string& s, int& pos, int currMin, int currMax)
    {
	if (pos >= s.size()) return nullptr;
	int val = *reinterpret_cast<const int*>(s.data() + pos);
	//check if this value is still in  this sutree
	if(val < currMin || val > currMax) return nullptr;
	pos += sizeof(val);

	//recurse the left and right substree
	TreeNode *root = new TreeNode(val);
	root->left = deserialize(s, pos, currMin, val);
	root->right = deserialize(s, pos, val, currMax);
	return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




























