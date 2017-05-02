// A C++ program to represent the graph by different ways: 
// add by edges but represented by adjacenet lists
#include <bits/stdc++.h>
#include <vector>
#include <list>
using namespace std;

typedef struct adjList
{
    int value;
    vector<int> adj_nodes;
}adj_list;

class graph
{
    //dynamic graph, no of vertices will grow when new edges are added
    int V;
    int E;

    //representation of edges
    vector<pair<int, int>> edges;

    //representation of adjacent lists
    vector<adj_list> adj_lists;

protected:
    int edges_2_adj_lists();

public:
    //constructor
    graph(){}

    //destructor, need release all the resource
    //including the edges and adjacent lists
    ~graph();

    //add edge the graph
    void add_edge_only(int u, int v);
    void add_edge_update(int u, int v);

    //detect the cycle for graph
    bool find_cycle();

    //topological sorting for the graph
    bool tsort();
}
