/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (49.64%)
 * Total Accepted:    31.3K
 * Total Submissions: 63K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai <
 * 231.
 * 
 * Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 * 
 * Could you do this in O(n) runtime?
 * 
 * Example:
 * 
 * Input: [3, 10, 5, 25, 2, 8]
 * 
 * Output: 28
 * 
 * Explanation: The maximum result is 5 ^ 25 = 28.
 * 
 * 
 */
class TrieNode
{
public:
    int val;
    TrieNode* left;
    TrieNode* right;
    TrieNode(int val):left(nullptr), right(nullptr), val(val) {}
};

class Trie
{
    TrieNode* root;
public:
    Trie() {
	root = new TrieNode(0);
    }

    void insert(int num)
    {
	TrieNode *node = root;
	if(!root) return;

	for(int i = 31; i >= 0; i--)
	{
	    int temp = num & (1<<i);
	    if(temp == 0) // zeor at bit i
	    {
		if(!node->right) node->right = new TrieNode(0);
		node = node->right;
	    }
	    else
	    {
		if(!node->left) node->left = new TrieNode(1);
		node = node->left;
	    }
	}
    }

    //find the first TrieNode that has left and right
    TrieNode* findFirstFullRoot(int& level)
    {
	TrieNode* node = root;
	level = 31;
	if(!node) return nullptr;
	while(!node->left || !node->right)
	{
	    node = node->left ? node->left : node->right;
	    if(!node) break;
	    level--;
	}

	return node;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
	//use a trie to store all the numbers,
	//then compare each number with the trie to find the local largest xor 
	//update the largest xor result each time
	//thus the actual time complexity would be O(32*n)
	//could be optimized by find the better root start from the biggest number
	//The trie could be implemented by binary tree as each bit is 0 or 1
	//each trie node also has its own value, 0 or 1 used for xor with the number

	//build the Trie
	Trie xorTrie;
	for(auto n : nums)
	{
	    xorTrie.insert(n);
	}
	int top_level = 31;
	TrieNode *firstFullRoot = xorTrie.findFirstFullRoot(top_level);
	if(!firstFullRoot || top_level < 0) return 0; 
	//iterate the numbs to update the maximum xor result
	int max_result = 0;
	TrieNode *currNode = firstFullRoot;
	for(auto n : nums)
	{
	    int local_res = 0;
	    for(int i = top_level; i >=0; i--) 
	    {
		int thisBit = n & (1 << i);
		if(currNode->left && currNode->right)	
		{
		    currNode = thisBit ? currNode->right : currNode->left;
		}
		else
		{
		    currNode = currNode->left ? currNode->left : currNode->right;
		}
		local_res += (currNode->val << i) ^ thisBit;
	    }
	    max_result = max(max_result, local_res);

	    currNode = firstFullRoot; //don't forget to go to the fullroot
	}
	return max_result;
    }
};
