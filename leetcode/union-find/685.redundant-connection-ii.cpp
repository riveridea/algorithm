/*
 * [685] Redundant Connection II
 *
 * https://leetcode.com/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (30.87%)
 * Total Accepted:    23.5K
 * Total Submissions: 76.3K
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
	//add edge one by one
	//1. if found the virtex pointed by two parent, don't add the second edge(acatually already removed), store the first edge
	//2. if added, then detect circle by union-find, if yes, store the last edge
	//3. after all the edges are added, check if 
	//   a) last == -1, means no circle, just returen the second edge as this is the removed
	//   b) last != -1 and second == -1, means just a circle but there is no point with two parents, return the last edge
	//   c) in this case, no circle and with one point having two parents, return the first edge or the second

	//init the parents and disjoint set
	int n = edges.size();
	vector<int> parents(n+1, -1); //store the edge pointing to him
	vector<int> dset(n+1, -1);

	int first = -1, second = -1, last = -1;
	int index = -1; 
	for(auto e : edges )
	{
	    index++;
	    int p = e[0], c = e[1];
	    if(parents[c] != -1) 
	    {
		first = parents[c];
		second = index;
		continue; //don't union p and c, this edge is not added
	    }
	    parents[c] = index;

	    //union p and c(add this edge), detect circle
	    int s = find(dset, p);
	    if(s == c) 
		last = index;
	    else 
		dset[c] = s;
	}

	if (last == -1)
	    return edges[second];
	else if(second == -1) 
	    return edges[last];
	else
	    return edges[first];
    }

private:
    int find(vector<int>& dset, int p)
    {
	if(dset[p] == -1)
	    return p;
	else
	{
	    return find(dset, dset[p]);
	}
    }
};



































