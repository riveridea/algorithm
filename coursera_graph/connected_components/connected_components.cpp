#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, int v, vector<bool> &visited)
{
	visited[v] = true; //firstly mark it as visited

	for(vector<int>::iterator itr = adj[v].begin();
					itr != adj[v].end();
					itr++)
	{
		if(visited[*itr] == false)
			dfs(adj, *itr, visited);
	}		
}

int number_of_components(vector<vector<int> > &adj) {
  	int res = 0;
  	//write your code here
  	//use dfs for each unvisisted node and increase the 
  	//components number 
  	int v = adj.size();
  	vector<bool> visited(v, false);

  	for(int i = 0; i < v; i++)
  	{
		if(visited[i] == false)
		{
			//only for unvisited node, after dfs, res is increased
			dfs(adj, i, visited);
			res++;
		}		
  	}
  	return res;
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
  std::cout << number_of_components(adj);
}
