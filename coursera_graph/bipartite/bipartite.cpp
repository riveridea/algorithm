#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bfs(vector<vector<int> > &adj, int s)
{
    vector<int> color(adj.size(), -1);
    vector<int> dist(adj.size(), -1);

    queue<int> q;

    q.push(s);
    dist[s] = 0;
    color[s] = 0;

    while(!q.empty())
    {
	int v = q.front();
	q.pop();

	for(vector<int>::iterator itr = adj[v].begin();
		itr != adj[v].end();
		itr ++)
	{
	    if(dist[*itr] == -1)
	    {
		q.push(*itr);
		if(color[v] != -1)
		{
		    color[*itr] = !color[v];
		    dist[*itr] = dist[v] + 1;
		}
		else
		{
		    printf("color error for node %d \n", v);
		    return 0;
		}
	    }
	    else if(color[*itr] == color[v])
	    {
		return 0;
	    }
	}
    }

    return 1;
}

int bipartite(vector<vector<int> > &adj) {
    //write your code here
    //use bfs to set different color for adjacent nodes
    //but when the adjacent node is already colored
    //check the color if it is the same with current node
    //return 0

    //do bfs from the node 1
    return bfs(adj, 0);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
