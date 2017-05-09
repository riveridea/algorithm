#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int dfs(vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &on_path, int v)
{
    visited[v] = true;
    on_path[v] = true;

    //dfs for the adjacent nodes
    for(vector<int>::iterator itr = adj[v].begin();
	    itr != adj[v].end();
	    itr ++)
    {
	if(on_path[*itr] == true || dfs(adj, visited, on_path, *itr))	
	    return 1;
    }

    return on_path[v] = false; //finish dfs for this node, not back again
}

int acyclic(vector<vector<int> > &adj) {
    //write your code here
    //need to check if the node on a path (not finished)
    //can be reached again
    //visisted is true when dfs does not mean it is a cycle
    //this node could have multiple sources
    
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<bool> on_path(V, false);

    for(int i = 0; i < V; i++)
    {
	if((visited[i] == false) && dfs(adj, visited, on_path, i))
	{
	    return 1;	
	}
    }

    return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
