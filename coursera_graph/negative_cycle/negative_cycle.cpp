#include <iostream>
#include <vector>

using std::vector;

#define INF 0x3f3f3f3f

int relax(int u, int v, vector<int> &dist, int cost)
{
    int result;
    int new_dist = dist[u] + cost;
    //printf("dist[%d] = %d, dist[%d] = %d, w(%d, %d) = %d\n", 
//	    v, dist[v], u, dist[u], u, v, cost);
    if(dist[v] > new_dist)
    {
	dist[v] = new_dist;
//	printf("new dist[%d] = %d\n", v, dist[v]);
	return 1;
    }
    else
    {
	return 0;
    }
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
    //write your code here
    //Bellman-ford algorithm
    //first run Bellman-ford algorithm - iterate V -1 times
    //then run the V-th times, once any relax detected, return 1
    //if no relax detected, return 0
    
    //initiaize dist array
    vector<int> dist(adj.size(), INF);
    //bellman-ford - V -1 iterations
    int V = adj.size();
    for(int i = 0; i < V - 1; i++)
    {
	//relax all the edges, by looping all the adjacent lists
	int u = 0;
	for(vector<vector<int> >::iterator itr = adj.begin();
		itr != adj.end();
		itr++, u++)
	{
	    int v = 0;
	    for(vector<int>::iterator itr2 = itr->begin();
		    itr2 != itr->end();
		    itr2++, v++)
	    {
		relax(u, *itr2, dist, cost[u][v]);	
	    }
	}
    }

    //the V-th iteration to detect the negative cycle
    //
    int u = 0;
    for(vector<vector<int> >::iterator itr = adj.begin();
	    itr != adj.end();
	    itr++, u++)
    {
	int v = 0;
	for(vector<int>::iterator itr2 = itr->begin();
    	        itr2 != itr->end();
    	        itr2++, v++)
    	{
    	    if(relax(u, *itr2, dist, cost[u][v]))
	    {
		return 1; 
	    }	
    	}
    }

    return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
