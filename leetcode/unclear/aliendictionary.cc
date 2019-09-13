#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        //find the order, apparently it is a topologcal sorting problem
        //1. make graph
        //2. top sorting with the graph,
        //question is how to avoid cycle? 
        //two points about this problem:
        //for those letter which has no pre or post, add it to graph whatever
        //detect cycle, don't forget!! use the total vertiex number to compare
        //with the 
        
        vector<unordered_set<int> > graph(26);
        vector<int> indegrees(26);
        vector<int> result;
        
        int row_size = words.size();
        vector<int> lens(row_size);
        
        //make graph
	    int stop = '$' - 'a';
        int count = 0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
		        int add = words[i][j] - 'a';
                if(graph[add].empty())
                {
                    graph[add].insert(stop);
                    count++;
                }
            }
        }	    
	    
	    
        for(int i = 0; i < row_size - 1; i++)
        {
            int len1 = words[i].size(), len2 = words[i+1].size();
            for(int j = 0; j < min(len1, len2); j++)
            {
                int u = words[i][j] - 'a';
                int v = words[i+1][j] - 'a';
		if(u != v) 
                {
                    if(graph[u].find(v) == graph[u].end())
		    {
                        graph[u].insert(v);
			            indegrees[v]++;
		    }
		    break;
                }
            }
        }
       	
        //topological sorting
        queue<int> q;
        for(int k = 0; k < indegrees.size(); k++)
        {
            if(indegrees[k] == 0 && !graph[k].empty())
            {
                q.push(k);
            }
        }
        //int cnt = 0;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            //if(graph[n].empty()) continue;
            result.push_back(n);
            for(auto neigh : graph[n])
            {
                if(neigh != stop && (--indegrees[neigh] == 0))
                {
                    q.push(neigh);
                }
            }
            count--;
        }
        
        if(count != 0) return "";
            
        //convert the results to string
        string s;
        for(auto v : result)
        {
            s += (v + 'a');
        }
        
        return s;
    }
};

int main()
{
    vector<string> matrix = {"wrt", "wrf", "er", "ett", "rftt"};// {"wrt", "wrf", "er", "ert", "ett", "rftt"};
    Solution s;
    string result = s.alienOrder(matrix);
    cout << result << endl;
}
