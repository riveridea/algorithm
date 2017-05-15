#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;

#define INF 0x3f3f3f3f
//define the comparison for priority queue
class comparedist
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
	return a.second > b.second;
    }
};

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

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
    //write your code her
    //dijkstra algorithm
    //cost is the weight on each edge

    //1. init the distance to infinity for each vertex
    //   and made the priority queue
    vector<int>  dist(adj.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, comparedist> 
	pri_q;

    //2. set the start point
    dist[s] = 0;
    pri_q.push(make_pair(s, 0));
    //3. while queue is not empty to go thru the node on path
    while(!pri_q.empty())
    {
	//extract the min
	pair<int, int> u_pair = pri_q.top();	
	int u = u_pair.first;
	int u_dist = u_pair.second;
//	printf("get top u = %d, dist[u] = %d\n", u, u_dist);
	
	if(u_pair.first == t) return u_dist;
	
	//relax the edges of u
	int i = 0;
	for(vector<int>::iterator itr = adj[u].begin();
		itr != adj[u].end();
		itr++, i++)
	{
	    if (relax(u, *itr, dist, cost[u][i])) //dist[v] changed to less value
		pri_q.push(make_pair(*itr, dist[*itr]));
	}

        pri_q.pop();
    }

    return -1;
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
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, cost, s, t);
}
