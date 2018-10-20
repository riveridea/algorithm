/*
 * [323] Number of Connected Components in an Undirected Graph
 *
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
 *
 * algorithms
 * Medium (49.97%)
 * Total Accepted:    45.8K
 * Total Submissions: 91.7K
 * Testcase Example:  '5\n[[0,1],[1,2],[3,4]]'
 *
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each
 * edge is a pair of nodes), write a function to find the number of connected
 * components in an undirected graph.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]
 * 
 * ⁠    0          3
 * ⁠    |          |
 * ⁠    1 --- 2    4 
 * 
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
 * 
 * ⁠    0           4
 * ⁠    |           |
 * ⁠    1 --- 2 --- 3
 * 
 * Output:  1
 * 
 * 
 * Note:
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 * 
 */
/*
 * [323] Number of Connected Components in an Undirected Graph
 *
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph
 *
 * algorithms
 * Medium (48.29%)
 * Total Accepted:    30.6K
 * Total Submissions: 63.4K
 * Testcase Example:  '5\n[[0,1],[1,2],[3,4]]'
 *
 * 
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each
 * edge is a pair of nodes), write a function to find the number of connected
 * components in an undirected graph.
 * 
 * 
 * 
 * ⁠   Example 1:
 * 
 * 
 * ⁠    0          3
 * ⁠    |          |
 * ⁠    1 --- 2    4
 * 
 * 
 * ⁠   Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
 * 
 * 
 * ⁠   Example 2:
 * 
 * 
 * ⁠    0           4
 * ⁠    |           |
 * ⁠    1 --- 2 --- 3
 * 
 * 
 * ⁠   Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 * 
 * 
 * 
 * Note:
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 * 
 */
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
	//union find algorthm 
	//suppose very beginning we have n connected components
	//union the two endpoints of each edges and decrease the number
	//of connected components
	vector<int> parents(n);
	//initialize the parents to its own
	iota(parents.begin(), parents.end(), 0); //successive values	

	//iterate the edges
	for(auto e : edges)	
	{
	    int s = findset(parents, e.first);
	    int d = findset(parents, e.second);

	    parents[s] = d; //union the two endpoint
	    if( s != d)
	    {
		n--;
	    }

	}

	return n;
    }
private:
    int findset(vector<int>& parents, int i)
    {
	return parents[i] == i ? i : findset(parents, parents[i]);
    }
};

