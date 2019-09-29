/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (43.93%)
 * Total Accepted:    47.5K
 * Total Submissions: 107.6K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */
class Solution {
public:
    bool relax(int u, int v, vector<int>& dist, int cost){
        int new_dist = dist[u] + cost;
        if(new_dist < dist[v]){
            dist[v] = new_dist;
            return true; 
        }
        return false;
    }

    void dijkstra(vector<vector<int>>& graph, 
                  vector<int>& dist, 
                  vector<vector<int>>& cost, 
                  int K)
    {
        priority_queue<pair<int, int>, vector<pair<int,int> >, greater<void>> q;

        dist[K-1] = 0;
        q.push(make_pair(0, K-1));
        while(!q.empty()){
            pair<int, int> u_info = q.top();
            q.pop();
            int u = u_info.second, u_dist = u_info.first;

            //if(u_dist == INT_MAX) continue; // no need to check
            for(auto v: graph[u]){
                if(relax(u, v, dist, cost[u][v]))
                    q.push(make_pair(dist[v], v));
            }
        }
    }


    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //use dijkstra algorithm to update each nodes's shortest distance from K
        //the dijkstra algorithm:
        //initiate a dist array to INT_MAX for each node
        //prepare a priority queue Q to store the current minimum distance node as 
        //the next v
        //while Q is not empty
        //    u = extract_min(Q)
        //    Q.pop()
        //    for(v : u.adjacents)
        //        realx(u, v, dist)
        //        push update u's dist to Q
        //
        //after dijkstra is exeucted, check if there are still INT_MAX if yes return -1
        //else keep looking for the max distance which is the answer

        //1.build graph
        vector<vector<int>> g(N);
        vector<vector<int>> cost(N, vector<int>(N, INT_MAX)); 
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0]-1, v = times[i][1]-1, c = times[i][2];
            g[u].push_back(v);
            cost[u][v] = c; 
        }

        vector<int> dist(N, INT_MAX);
        dijkstra(g, dist, cost, K);
        
        //check the dist
        int ans = INT_MIN;
        for(auto d : dist){
            if(d == INT_MAX) return -1;
            ans = max(ans, d);
        }
        return ans;
    }
};
