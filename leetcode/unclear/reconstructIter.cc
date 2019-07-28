#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        //I think this is a topological sorting problem
        //make graph, use map and set
        unordered_map<string, unordered_set<string> > graph;
        unordered_map<string, int> in_degrees;
        int count = 0;
        for(auto edge : tickets)
        {
            graph[edge.first].insert(edge.second); 
	    in_degrees[edge.first]; //make sure the first exit
            count++;
            if(graph.find(edge.second) == graph.end() ) 
            //make sure the destination is also init
            {
                graph[edge.second];
                count++;
            }
            in_degrees[edge.second]++;
        }
       
        //cout << count << endl;	
        //construct the zero degree queue
        queue<string> zz;
        vector<string> result;
        for(auto node : in_degrees)
        {
	    cout << node.second << " " << node.first << endl;
            if( node.second == 0) zz.push(node.first);
        }
        
        //topological sorting
        while(!zz.empty())
        {
            string n = zz.front();
            zz.pop();
            result.push_back(n);
	    cout << n << endl;
            for(auto neigh : graph[n])
            {
                if(--in_degrees[neigh] == 0) zz.push(neigh);
            }
            count--;
        }
        
        //if(count != 0) return {};
        
        return result;
    }
};

int main()
{
    vector<pair<string, string>> tickets = 
   //{make_pair("MUC", "LHR"), make_pair("JFK", "MUC"), make_pair("SFO", "SJC"), make_pair("LHR", "SFO")};
   {make_pair("JFK", "ATL"), make_pair("ATL", "JFK")};

    Solution s;
    vector<string> result  = s.findItinerary(tickets);
    for(auto s : result)
	cout << s << endl;
}
