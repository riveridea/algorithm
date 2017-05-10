#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
    //write your code here
    //bfs from s then if t is found, return the distance
    //otherwise return -1
    vector<int> dist(adj.size(), -1);
    queue<int> q; //to store the nodes discovered

    //push the source node firstly, llala
    q.push(s);
    dist[s] = 0; //don't forget to set the distance to itself
    //now go to while loop, excited? lalala
    while(!q.empty()) //as soon as there are something in the queue
    {
	//let us pop the front
	int u = q.front();
	q.pop();

	for(vector<int>::iterator itr = adj[u].begin();
		itr != adj[u].end();
		itr ++)
	{
	    if(dist[*itr] == -1) 
	    {
		//first time discovered
		if(*itr == t) return dist[u] + 1;
		else
		{
		    q.push(*itr);
		    dist[*itr] = dist[u] + 1;
		}
	    }
	}
    }

    return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
