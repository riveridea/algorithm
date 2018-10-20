/*
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (29.15%)
 * Total Accepted:    52.3K
 * Total Submissions: 179.4K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * For a undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 * 
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be
 * given the number n and a list of undirected edges (each edge is a pair of
 * labels).
 * 
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 * 
 * Example 1 :
 * 
 * 
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * 
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3 
 * 
 * Output: [1]
 * 
 * 
 * Example 2 :
 * 
 * 
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 * 
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5 
 * 
 * Output: [3, 4]
 * 
 * Note:
 * 
 * 
 * According to the definition of tree on Wikipedia: “a tree is an undirected
 * graph in which any two vertices are connected by exactly one path. In other
 * words, any connected graph without simple cycles is a tree.”
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 * 
 */
class Solution {
    public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        //dont try brutally using BFS
        //the basic idea is, remove leaves, until the final batch of leaves
        //don't have connected leaves to be cut. return those leaves
        
        if(n == 1) return {0}; //corner case
        
        //make graph
        vector<unordered_set<int> > graph(n); //use unordered_set for erase
        vector<int> degrees(n);
        for(auto e : edges)
        {
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
            degrees[e.first]++;
            degrees[e.second]++;
        }
        //find the frist batch of leaves
        vector<int> curr_leaves;
        
        for(int i=0; i< n; i++)
        {
            if(degrees[i] == 1) curr_leaves.push_back(i);
        }

        //vector<int> next_leaves;
        //now remove the leaves layer by layer
        while(1)
        {
            vector<int> next_leaves;
            for(int leaf : curr_leaves)
            {
                for(int neigh : graph[leaf])
                {
                    graph[neigh].erase(leaf);
                    if(--degrees[neigh] == 1) next_leaves.push_back(neigh);
                }
            }
            if(next_leaves.empty()) return curr_leaves; //last level of leaves
            curr_leaves = next_leaves;
            //next_leaves.clear();
        }
    }
};
