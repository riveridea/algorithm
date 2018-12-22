/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 *
 * https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (37.84%)
 * Total Accepted:    52.9K
 * Total Submissions: 139.8K
 * Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we
 * encounter a non-null node, we record the node's value. If it is a null node,
 * we record using a sentinel value such as #.
 * 
 * 
 * ⁠    _9_
 * ⁠   /   \
 * ⁠  3     2
 * ⁠ / \   / \
 * ⁠4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * 
 * For example, the above binary tree can be serialized to the string
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * Given a string of comma separated values, verify whether it is a correct
 * preorder traversal serialization of a binary tree. Find an algorithm without
 * reconstructing the tree.
 * 
 * Each comma separated value in the string must be either an integer or a
 * character '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could
 * never contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * 
 * 
 * Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: "1,#"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "9,#,#,1"
 * Output: false
 */
class Solution {
public:
    bool isValidSerialization(string preorder) {
	//firstly we try a stack way, push every node to stack from left to right
	//but when we meet a pattern "number, #, #" in the stack, this meana a leaf
	//is met, then we replace the "number, #, #" to "#" and going ahead to 
	//next node. If finally we get a stack with only "#", then this is a valid tree serization
	if (preorder.size() == 0) return false;
	if (preorder[preorder.size() - 1] != '#') return false;
	
	stack<char> s;
	bool onNum = false; // this is to indicate we are on a number than 1 digit
	preorder += ','; //dummy tail

	for(auto c : preorder)
	{
	    if(c == '#') // need to check the pattern "n, #,#" and cancel it
	    {
		while(!s.empty() && s.top() == '#')
		{
		    s.pop();// cancel a '#'
		    //check no more '#'
		    if(s.empty() || s.top() == '#') return false; //"n, #, #, #"
		    s.pop();//cancel a number
		}
		s.push('#');
	    }
	    else if(c == ',')
	    {
		if(onNum)  s.push('n'); // alrady done a number then push a placeholder
		onNum = false;
	    }
	    else
		onNum = true;
	}
	
	return s.size() == 1 && s.top() == '#';
    }
};











