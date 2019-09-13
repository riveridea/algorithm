/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (68.74%)
 * Total Accepted:    51.6K
 * Total Submissions: 74.9K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Return its postorder traversal as: [5,6,3,2,4,1].
 * 
 * 
 * Note:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
	//post order, left, right, root        
	//can we emulate the binary tree post-order traversal with iterative method?
	vector<int> res;
	if(!root) return res;

	//use a map to track how many childs not processed yet
	unordered_map<Node*, int> m;	
	stack<Node*> s;

	Node* node = root;
	Node* v = NULL;
	while(!s.empty() || node != NULL){
	    //push the most left
	    if(node != NULL){
		s.push(node);
		m[node] = node->children.size();
		if(node->children.size() > 0)
		{
		    m[node]--;
		    node = node->children[0];
		}
		else
		{
		    node = NULL; //reach the last left
		}
	    }
	    else{
		// get a new node from the stack
		node = s.top();
		int n = node->children.size();
		int ci = n - m[node];
		if(m[node] > 0 && node->children[ci] != v){
		    m[node]--;
		    node = node->children[ci];
		}
		else{
		    //all the children are processed
		    res.push_back(node->val);
		    v = node;
		    s.pop();
		    node = NULL;
		}
	    }
	}	
	return res;
    }
};
