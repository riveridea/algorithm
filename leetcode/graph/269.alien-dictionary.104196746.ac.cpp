/*
 * [269] Alien Dictionary
 *
 * https://leetcode.com/problems/alien-dictionary/description/
 *
 * algorithms
 * Hard (28.01%)
 * Total Accepted:    52.6K
 * Total Submissions: 187.8K
 * Testcase Example:  '["wrt","wrf","er","ett","rftt"]'
 *
 * There is a new alien language which uses the latin alphabet. However, the
 * order among letters are unknown to you. You receive a list of non-empty
 * words from the dictionary, where words are sorted lexicographically by the
 * rules of this new language. Derive the order of letters in this language.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ "wrt",
 * ⁠ "wrf",
 * ⁠ "er",
 * ⁠ "ett",
 * ⁠ "rftt"
 * ]
 * 
 * Output: "wertf"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x"
 * ]
 * 
 * Output: "zx"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * [
 * ⁠ "z",
 * ⁠ "x",
 * ⁠ "z"
 * ] 
 * 
 * Output: "" 
 * 
 * Explanation: The order is invalid, so return "".
 * 
 * 
 * Note:
 * 
 * 
 * You may assume all letters are in lowercase.
 * You may assume that if a is a prefix of b, then a must appear before b in
 * the given dictionary.
 * If the order is invalid, return an empty string.
 * There may be multiple valid order of letters, return any one of them is
 * fine.
 * 
 * 
 */
class Solution {
public:
    string alienOrder(vector<string>& words) {
        //find the order, apparently it is a topologcal sorting problem
        //1. make graph
        //2. top sorting with the graph,
        //question is how to avoid cycle?
        
        vector<unordered_set<int> > graph(26);
        vector<int> indegrees(26);
        vector<int> result;
        
        int row_size = words.size();
        
        //make graph
	    int stop = '$' - 'a';
        int count = 0;
        //init graph for every existed letter!!!
        //the letter could have no pre or post 
        //don't forget
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
		            break; //important!!!
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


