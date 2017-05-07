#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool dfs_reach(vector<vector<int> > &adj, int x, int y, vector<bool> &visited);

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  //use DFS to determine if destination y can be reachble 
  //from x
  int v = adj.size();//the number of vertices
  vector<bool> visited(v, false); 
  
  bool result = dfs_reach(adj, x, y, visited);
  return result;
}

bool dfs_reach(vector<vector<int> > &adj, int x, int y, vector<bool> &visited)
{
    visited[x] = true;

    if (x == y) return true;
    for(vector<int>::iterator itr = adj[x].begin();
		    itr != adj[x].end(); itr++)   
    {
    	if (visited[*itr] == false)
	{
	    //check if we found y
	    if((*itr == y) || dfs_reach(adj, *itr, y, visited))
			return true;
	}
    }
    
    return false;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
