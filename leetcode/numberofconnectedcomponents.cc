#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        //union and find algorithm
        
        //make graph
        graph.resize(n);
        for(auto e : edges)
        {
            graph[e.first].push_back(e.second);
	    graph[e.second].push_back(e.first);
        }
	//dump graph
	for(int i = 0; i < n; i++)
	{
	    for(auto neigh : graph[i])
		cout << i << "-->" << neigh << endl;
	}
        //initialize roots table
        roots.resize(n, -1);
        
        //finds new ilands
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            count++;
            roots[i] = i;
            for(auto neigh : graph[i])
            {
		if(roots[neigh] == -1) continue;
		cout << "trying to union " << i << " and " << neigh << endl;
                if(union_roots(i, neigh))
                    count--;
            }
	    cout << "finished " << i << "island current = " << count << endl;
        }
        
        return count;
    }
    
private:
    vector<vector<int> > graph;
    vector<int> roots; //store the root for every graph node

    int find_root(int node)
    {
        while(roots[node] != node)
        {
	    cout << "node = " << node << ";";
	    cout << "roots[node] = " << roots[node] << " ";
	    cout << "roots[roots[node]] = " << roots[roots[node]] << endl;
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }
    
    bool union_roots(int u, int v)
    {
        int root_u = find_root(u);
        int root_v = find_root(v);
        if(root_u != root_v)
        {
	    cout << "unioned " << u << "and" << v << endl;
            roots[root_u] = root_v;
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int n = 5;
    vector<pair<int, int>> poss =
    {
        make_pair(0, 1),
        make_pair(1, 2),
        make_pair(3, 4),
        //make_pair(1, 1)
        //make_pair(2, 1)
    };

    int result = s.countComponents(n, poss); 
}
