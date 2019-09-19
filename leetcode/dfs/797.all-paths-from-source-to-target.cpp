/*
 * [813] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (71.41%)
 * Total Accepted:    34K
 * Total Submissions: 47.7K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * Given a directed, acyclic graph of N nodes.  Find all possible paths from
 * node 0 to node N-1, and return them in any order.
 * 
 * The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
 * graph[i] is a list of all nodes j for which the edge (i, j) exists.
 * 
 * 
 * Example:
 * Input: [[1,2], [3], [3], []] 
 * Output: [[0,1,3],[0,2,3]] 
 * Explanation: The graph looks like this:
 * 0--->1
 * |    |
 * v    v
 * 2--->3
 * There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the graph will be in the range [2, 15].
 * You can print different paths in any order, but you should keep the order of
 * nodes inside one path.
 * 
 */
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	//let us firstl try recursive dfs + backtracking
	//backtracking means pop back the curren node after all the currnet node's children
	//are recursively processed
	vector<vector<int>> allpath;
	vector<int> path;
	dfs(graph, allpath, path, 0);
	return allpath;
    }
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& allpath, vector<int>& path, int curr){
	path.push_back(curr);
	if(curr == graph.size() - 1){
	    allpath.push_back(path);
	}
	else{
	    for(int child : graph[curr]){
		dfs(graph, allpath, path, child);	
	    }
	}
	//finished this curr, backtracking
	path.pop_back();
    }

};
