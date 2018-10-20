/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (35.10%)
 * Total Accepted:    155.6K
 * Total Submissions: 443.2K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //as the graph node value is int type, we use the node value to index 
        // the nodes, for non-int value, maybe key_to_index is needed 
        // also visited flags are accessed by node value
        // visited = true does not mean the cycle is detected!!
        // after all the adjacent nodes are dfsed, the onpath is set to 
        // false. then if the adjacent nodes is still onpath but now get
        // to be dfsed, cycle is detected!!
        
        //adjacent list is represneted by unordered_set<int>
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        
        //loop the vertices to perform DFS
        for(int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false; 
        }
        
        return true;
    }
private:
    //make graph to be represented by adjacent list from edges
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>>  graph(numCourses);
        for(auto pre : prerequisites)
        {
            graph[pre.first].insert(pre.second);
        }
        return graph;
    }
    
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited)
    {
        onpath[node] = visited[node] = true;
        //go through the adjcent list for this node
        for(int neigh : graph[node])
        {
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        }
        
        return onpath[node] = false;
    }

};
