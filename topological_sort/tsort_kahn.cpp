// A C++ programm to print topological sorting of a graph using indegrees

#include<bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph
{
    int V;      // No. of Vertices

    // pointers to an array containing adjacency list 
    list<int> *adj;

public:
    Graph(int V);     //constructor

    // function to add edge to graph
    void addEdge(int u, int v);

    // prints a Topological sort of the complete graph
    void topologicalSort();
};


// Class implementation
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

// topological sorting algorithm based on Khan's solution
void Graph::topologicalSort()
{
    //compute the indegree for all the vertices
    vector<int> in_degrees(V, 0);
    for (int u = 0; u < V; u++)
    {
	list<int>::iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
	    in_degrees[*itr]++;
	}
    }

    //pick all the vertices with 0 in degree to the queue
    queue<int> q;
    for (int u = 0; u < V; u++)
    {
	if(in_degrees[u] == 0) q.push(u);	
    }

    int cnt = 0; //count the visited nodes
    //whle loop to iterate all the neighboring nodes of popped node of the queue
    while(!q.empty())
    {
	//get the value of the top of the queue them remove it
	int u = q.front();
	q.pop();
	printf("%d \n", u);

	//looking into the neighboring nodes
	list<int>::iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
	    //decrease the in degree
	    in_degrees[*itr]--;
	    //check if can push to the queue
	    if(in_degrees[*itr] == 0) q.push(*itr);
	}

	cnt++;
    }

    if (cnt != V)
    {
	cout << "Cycle exists in graph \n";
	return;
    }
}

//Test 
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 5);
 
    cout << "topological sorting\n";
    g.topologicalSort();   
}
