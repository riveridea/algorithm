/*
<<<<<<< HEAD
=======
 * @lc app=leetcode id=685 lang=cpp
 *
>>>>>>> 9d4762b9ad97a2eb35a6e203316322ec793e8caf
 * [685] Redundant Connection II
 *
 * https://leetcode.com/problems/redundant-connection-ii/description/
 *
 * algorithms
<<<<<<< HEAD
 * Hard (30.87%)
 * Total Accepted:    23.5K
 * Total Submissions: 76.3K
=======
 * Hard (31.06%)
 * Total Accepted:    24.9K
 * Total Submissions: 80K
>>>>>>> 9d4762b9ad97a2eb35a6e203316322ec793e8caf
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 
 * In this problem, a rooted tree is a directed graph such that, there is
 * exactly one node (the root) for which all other nodes are descendants of
 * this node, plus every node has exactly one parent, except for the root node
 * which has no parents.
 * 
 * The given input is a directed graph that started as a rooted tree with N
 * nodes (with distinct values 1, 2, ..., N), with one additional directed edge
 * added.  The added edge has two different vertices chosen from 1 to N, and
 * was not an edge that already existed.
 * 
 * The resulting graph is given as a 2D-array of edges.  Each element of edges
 * is a pair [u, v] that represents a directed edge connecting nodes u and v,
 * where u is a parent of child v.
 * 
 * Return an edge that can be removed so that the resulting graph is a rooted
 * tree of N nodes.  If there are multiple answers, return the answer that
 * occurs last in the given 2D-array.
 * Example 1:
 * 
 * Input: [[1,2], [1,3], [2,3]]
 * Output: [2,3]
 * Explanation: The given directed graph will be like this:
 * ⁠ 1
 * ⁠/ \
 * v   v
 * 2-->3
 * 
 * 
 * Example 2:
 * 
 * Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
 * Output: [4,1]
 * Explanation: The given directed graph will be like this:
 * 5  2
 * ⁠    ^    |
 * ⁠    |    v
 * ⁠    4 
 * 
 * Note:
 * The size of the input 2D-array will be between 3 and 1000.
 * Every integer represented in the 2D-array will be between 1 and N, where N
 * is the size of the input array.
 * 
 */
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
	//The candidated of edge of redundancy is egde that causes one node who will have 
	//two parents.
	//the first step is to check if a adding edge would cause the duplicated parents.
	//if yes, record both the edges, the old one as ans1, the new one as ans2
	//then firstly make the new edge avoid thus this edge will not be visited 
	//in the 2nd step.
	//the next step is to find hte cycle
	//if cycle detected, then check ans1 exists or not
	//if ans1 exist, means the duplicated parents exists, then this ans1 is the answer
	//if ans1 does not exist, means no duplicated parents, then this new edge is the answer
	//if no cycle detected, just retrun ans2
	//use the union-find with path cmpression and union by size to accelerate
	
	vector<int> parent(edges.size() + 1, 0);
	vector<int> root(edges.size() + 1, 0);
	vector<int> sizes(edges.size() + 1, 1);
	
	vector<int> ans1; //old edge for duplicated parents
	vector<int> ans2; //new edge for duplicted parents

	//detect the duplicated parents
	for(auto& edge : edges){ //don't forget & 
	    int u = edge[0];
	    int v = edge[1];

	    if(parent[v] > 0) //find duplicated parent
	    {
		ans1 = {parent[v], v};
		ans2 = edge;

		//skip the new edge for the 2nd step of deteting the cycle
		edge[0] = edge[1] = -1;
	    }
	    parent[v] = u;
	}

	//detect the cycle
	for(auto& edge : edges)
	{
	    int u = edge[0];
	    int v = edge[1];
	    if(u < 0 || v < 0) continue;
	    if(union_set(u, v, root, sizes)){ //this edge causing a cycle
		return ans1.empty()?edge:ans1;
	    }	
	}

	return ans2;
	
    }

    //path compression
    int find(int v, vector<int>& root)
    {
	if(v == root[v])
	    return v;

	return root[v] = find(root[v], root);
    }

    bool union_set(int a, int b, vector<int>& root, vector<int>& sizes)
    {
	if(root[a] == 0) root[a] = a;
	if(root[b] == 0) root[b] = b;
	a = find(a, root);
	b = find(b, root);
	if(a != b)
	{
	    if(sizes[a] < sizes[b])
		swap(a, b);
	    
	    root[b] = a;
	    sizes[a] += sizes[b];

	    return false;
	}
	return true;
    }
};
