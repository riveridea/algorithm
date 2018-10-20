/*
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (30.00%)
 * Total Accepted:    57.7K
 * Total Submissions: 192.4K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 * 
 * Note:
 * 
 * 
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"].
 * But it is larger in lexical order.
 * 
 * 
 */
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        //this is not a topological problem
        //you need to do DFS, but need to make sure all the output 
        //nodes are on the path, even there is cycle
        if(tickets.size() == 0) return {};
        
        unordered_map<string, multiset<string> > graph;
        vector<string> result;
        
        //make graph
        for(auto edge : tickets)
        {
            graph[edge.first].insert(edge.second);
        }
        
        stack<string> dfs;
        dfs.push("JFK");
        while(!dfs.empty())
        {
            string cur_airport = dfs.top();
            //deterin if this airport can be popped to result
            if(graph[cur_airport].size() == 0)
            {
                //find a final destination
                result.push_back(cur_airport);
                dfs.pop(); //foreget this airport now
            }
            else
            {
                //need to go ahead, but need to cut the first neighbor and
                //also put this neghbor into stack
                dfs.push(*(graph[cur_airport].begin()));
                graph[cur_airport].erase(graph[cur_airport].begin());
            }
        }
        
        //don't forget reverse 
        reverse(result.begin(), result.end());
        return result;
    }
};


