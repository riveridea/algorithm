#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        //if (edges.size() != n-1) return false;
        
        vector<int> nodes(n,0);
        for(int i=0; i<n; i++) 
	{
	    nodes[i] = i;
	    cout << "node[" << i << "]=" << nodes[i] << endl;
	}
        for(int i=0; i<edges.size(); i++){
            int f = edges[i].first;
            int s = edges[i].second;
            while(nodes[f]!=f) 
            {
                f = nodes[f];
            }
            while(nodes[s]!=s) s = nodes[s];
            if(nodes[f] == nodes[s]) return false;
            nodes[s] = f;
            cout << f << endl; 
        }
        
        //return true;
        return edges.size() == n-1;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int>> edges =
    {make_pair(0,1), make_pair(1,4), make_pair(0,2), make_pair(0, 3), make_pair(1,2)};

    cout << s.validTree(5, edges) << endl;
}
