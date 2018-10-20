/*
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (31.97%)
 * Total Accepted:    110.9K
 * Total Submissions: 346.8K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //two things:
		//1. the graph is represented by vector<unordered_set<int> > as the input is edge
		//2. DFS with post-order operation to push value to front of vector 
		
		//make graph
		vector<unordered_set<int> > graph(numCourses);
		for(vector<pair<int, int> >::iterator itr = prerequisites.begin();
				itr != prerequisites.end();
				itr++)
		{
			graph[itr->first].insert(itr->second);
		}
		
		//dfs
		//initialization
		vector<bool> visited(numCourses, 0);
		vector<int> ordered;
		
		if(detect_cycle(numCourses, graph, visited)) return ordered; 
		
		//no process acyclic 
		for(vector<bool>::iterator itr = visited.begin();
		                           itr != visited.end();
		                           itr++)
		{
		    *itr = false;
		}
		for(int i = 0; i < numCourses; i++)
		{
			if(!visited[i])
			{
			    dfs(graph, i, visited, ordered);
			}
		}
		//reverse the ordered 
		//reverse(ordered.begin(), ordered.end());
		
		return ordered;
    }
	
private:
    bool detect_cycle(int numCourses, vector<unordered_set<int> > &graph, vector<bool> &visited)
    {
        vector<bool> onpath(numCourses, false);
        
        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i] && dfs_cycle(graph, i, visited, onpath))
                return true;
        }
        
        return false;
    }
    
    bool dfs_cycle(vector<unordered_set<int> > &graph, int node, vector<bool> &visited, vector<bool> &onpath)
    {
        visited[node] = true;
        onpath[node] = true;
        
        for(auto next : graph[node])
        {
            if(onpath[next] || dfs_cycle(graph, next, visited, onpath))
            {
                return true; //cyclec detected   
            }
        }
        
        onpath[node] = false; //finish the dfs for this node, no cycle detected
        
        return false;
    }

	void dfs(vector<unordered_set<int> > &graph, int node, vector<bool> &visited, vector<int> &ordered)
	{
		visited[node] = 1; 
		
		for(auto next : graph[node])
		{
			if(!visited[next])
			{
			    dfs(graph, next, visited, ordered);
			}
		}
		
		//post order 
		ordered.push_back(node);
	}
};


