//Graph representation implementation
#include "graph.h"

//constructor
graph::graph
{
    V = 0; //no vertices in the beginning
    E = 0; 
}

~graph()
{
    //TODO will release the resources 
}

void graph::add_edge(int u, int v)
{
    //TODO update the edges only
    //adjacent list will be update once we want to convert
    //the edges to adjacnet list
}

bool graph::find_cycle()
{
    //TODO find the cycle, based on the DFS
}

bool graph::tsort()
{
    //TODO topological sort if no cycle is found 
}

vector<unordered_set<int>> 
grpah::make_graph_from_edges()
{

}

//test code
int main()
{
    graph g;
    graph.make_graph_from_edges();
    //g.add_edge
    return 0;
}
