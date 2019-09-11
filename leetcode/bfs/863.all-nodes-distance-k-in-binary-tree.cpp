/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (49.80%)
 * Total Accepted:    32.1K
 * Total Submissions: 64.3K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
 * 
 * 
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
	//create parent for each child
	//then do BFS, for its right, left and parent
	unordered_map<TreeNode*, TreeNode*> par;

	//dfs to update the par
	stack<TreeNode*> s;
	s.push(root);
	while(!s.empty()){
	    TreeNode* p = s.top(); s.pop();
	    if(p->left) {
		par[p->left] = p;
		s.push(p->left);
	    }
	    if(p->right){
		par[p->right] = p;
		s.push(p->right);
	    } 
	}

	//now do BFS for the whole graph (Tree + Map)
	unordered_set<TreeNode*> v; //
	v.insert(target);

	queue<TreeNode*> q;
	q.push(target);
	int level = 0;
	vector<int> ans;
	//if(K == 0) 
	//{
	//    ans.push_back(q.front()->val);
	//    return ans;
	//}

	while(!q.empty()){
	    if(level == K){
		while(!q.empty()){
		    ans.push_back(q.front()->val);
		    q.pop();
		}
		break;
	    }
	    int n = q.size();

	    while(n){
		TreeNode* c = q.front();
		q.pop();
		n--;
		if(c->left && v.find(c->left) == v.end()) {
		    q.push(c->left);
		    v.insert(c->left);
		}
		if(c->right && v.find(c->right) == v.end()) {
		    q.push(c->right);
		    v.insert(c->right);
		}
		if(c!= root && v.find(par[c]) == v.end()) {
		    q.push(par[c]);
		    v.insert(par[c]);
		}
	    }
	    level++;
	}
	return ans;
    }
};
