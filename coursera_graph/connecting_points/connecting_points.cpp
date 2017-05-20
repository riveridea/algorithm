#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using namespace std;

//Kruskcal algorithm, edges based 
typedef struct Edge
{
    double cost;
    pair<int, int> line;    
} edge;

//union and find algorithm for disjoint sets
int find(vector<int> parent, int i)
{
    if(parent[i] == -1)
	return i;
    else
	return find(parent, parent[i]);
}

void Union(vector<int> parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

    parent[xset] = yset;
}

bool compare_edge(edge a, edge b)
{
    return a.cost < b.cost;
}

double line_len(pair<int, int> pointa, pair<int, int> pointb)
{
    return sqrt(pow(pointa.first - pointb.first, 2) + 
	        pow(pointa.second- pointb.second, 2));
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  //we need to convert the vertexs(x, y) to index (v)
    vector<pair<int, int> > vertices;
    int sizex = x.size();
    int sizey = y.size();
    if (sizex != sizey)
    {
	return 0;
    }
    
    //make vertecies
    for(int i = 0; i < sizex; i++)
    {
	pair<int, int> vertex(x[i], y[i]);
	vertices.push_back(vertex);	
    }
    vector<int> parent(sizex, -1);

    //make graph
    vector<edge> graph;
    for(int j = 0; j < sizex; j++)
    {
	for(int k = j + 1; k < sizex; k++)
	{
	    //construct edge and insert to graph
	    pair<int, int> line(j, k);
	    double cost = line_len(vertices[j], vertices[k]);
	    edge e;
	    e.line = line;
	    e.cost = cost;
	    graph.push_back(e); 
	    cout << "(" << j << "," << k << ")";
	    cout << "distance: " << e.cost <<endl;
	}
    }
    //sort the edges
    sort(graph.begin(), graph.end(), compare_edge);
    for(vector<edge>::iterator itr = graph.begin();
			       itr != graph.end();
			       itr++)
    {
	cout << "(" << itr->line.first << "," << itr->line.second << ")";
	cout << "distance: " << itr->cost <<endl;
    }

    //now let us do the real work
    //add each edge as non-decreasing order, if this new edge is not causing
    //cycle. use the find and union algorithm
    for(vector<edge>::iterator itr = graph.begin();
			       itr != graph.end();
			       itr++)
    {
	//find the set for each endpoint of the edge
	int u = itr->line.first;
	int v = itr->line.second;
	int uset = find(parent, u);
	int vset = find(parent, v);
	if(uset != vset)
	{
	    //union the two points to the same set
	    Union(parent, u, v);
	    //add the edge, we just need the cost
	    result += itr->cost;
	}
    }

    return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
