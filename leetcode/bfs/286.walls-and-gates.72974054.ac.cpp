/*
 * [286] Walls and Gates
 *
 * https://leetcode.com/problems/walls-and-gates/description/
 *
 * algorithms
 * Medium (46.76%)
 * Total Accepted:    57.2K
 * Total Submissions: 122.3K
 * Testcase Example:  '[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]'
 *
 * You are given a m x n 2D grid initialized with these three possible
 * values.
 * 
 * 
 * -1 - A wall or an obstacle.
 * 0 - A gate.
 * INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to
 * represent INF as you may assume that the distance to a gate is less than
 * 2147483647.
 * 
 * 
 * Fill each empty room with the distance to its nearest gate. If it is
 * impossible to reach a gate, it should be filled with INF.
 * 
 * Example: 
 * 
 * Given the 2D grid:
 * 
 * 
 * INF  -1  0  INF
 * INF INF INF  -1
 * INF  -1 INF  -1
 * ⁠ 0  -1 INF INF
 * 
 * 
 * After running your function, the 2D grid should be:
 * 
 * 
 * ⁠ 3  -1   0   1
 * ⁠ 2   2   1  -1
 * ⁠ 1  -1   2  -1
 * ⁠ 0  -1   3   4
 * 
 * 
 */
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //try breath first 
        //for each node, try the breath first and get 
        //the distance when it first reach the 0
        //setup the queue start from the all 0 point
        //the key is if the next point has value less or equal to the update value, then skip
        
        //1. build the queue 
        queue<pair<int, int> > canReach;
        int row = rooms.size();
        if(row == 0) return; // incase empty input
        int col = rooms[0].size();
        vector<pair<int, int> > nexts = {{0, 1}, {1, 0},{0, -1},{-1, 0}};
        for(int i=0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                //only 0 points are initialized
                if(rooms[i][j] == 0)
                    canReach.emplace(i,j);
            }
        }
        
        //2. start BFS 
        while(!canReach.empty())
        {
            //get the top of the queue
            int r = canReach.front().first, c = canReach.front().second;
            canReach.pop();
            
            //perfrom BFS for (r,c)
            for(auto next: nexts){
                //get next 
                int x = r + next.first, y = c + next.second;
                //skip some nodes - key is to ensure only smallest distance is used for update
                if(x >= row || y >= col || x < 0 || y < 0 || rooms[x][y] <= rooms[r][c] + 1) continue;
                
                //update the value
                rooms[x][y] = rooms[r][c] + 1;
                //push this node to queue
                canReach.emplace(x,y);
            }
        }
        
    }
};
