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

void graph::add_edge_only(int u, int v)
{
    //TODO update the edges only
    //adjacent list will be update once we want to convert
    //the edges to adjacnet list
}

void graph::add_edge_update(int u, int v)
{
    //TODO update the edges and also the adjacent lists 
}

bool graph::find_cycle()
{
    //TODO find the cycle, based on the DFS
}

bool graph::tsort()
{
    //TODO topological sort if no cycle is found 
}

//test code
int main()
{
    graph g;

    //g.add_edge
    
    return 0;
}
