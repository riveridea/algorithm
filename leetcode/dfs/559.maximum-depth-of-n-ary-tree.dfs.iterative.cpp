/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (66.15%)
 * Total Accepted:    63.5K
 * Total Submissions: 96K
 * Testcase Example:  '{"$id":"1","children":[{"$id":"2","children":[{"$id":"5","children":[],"val":5},{"$id":"6","children":[],"val":6}],"val":3},{"$id":"3","children":[],"val":2},{"$id":"4","children":[],"val":4}],"val":1}'
 *
 * Given a n-ary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
 * 
 * For example, given a 3-ary tree:
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return its max depth, which is 3.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The depth of the tree is at most 1000.
 * The total number of nodes is at most 5000.
 * 
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
    int maxDepth(Node* root) {
	//easy problem but let's try DFS        
	//iterative
	//but for DFS, you need to record the level for each node
	if(!root) return 0;
	stack<pair<Node*, int>> s;
	int d = 0;
	pair<Node*, int> rn(root, 1);
	s.push(rn);
	
	int g_depth = 0;
	while(!s.empty()){
	    pair<Node*, int> p = s.top(); s.pop();
	    int l_depth = p.second;
	    g_depth = max(g_depth, l_depth);
	    Node* nd = p.first;
	    for(Node* c : nd->children){
		pair<Node*, int> cp(c, l_depth+1);
		s.push(cp);
	    }
	}
	return g_depth;
    }
};
