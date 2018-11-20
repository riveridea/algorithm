/*
 * [505] The Maze II
 *
 * https://leetcode.com/problems/the-maze-ii/description/
 *
 * algorithms
 * Medium (40.72%)
 * Total Accepted:    18.9K
 * Total Submissions: 46.4K
 * Testcase Example:  '[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]\n[0,4]\n[4,4]'
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go
 * through empty spaces by rolling up, down, left or right, but it won't stop
 * rolling until hitting a wall. When the ball stops, it could choose the next
 * direction.
 * 
 * Given the ball's start position, the destination and the maze, find the
 * shortest distance for the ball to stop at the destination. The distance is
 * defined by the number of empty spaces traveled by the ball from the start
 * position (excluded) to the destination (included). If the ball cannot stop
 * at the destination, return -1.
 * 
 * The maze is represented by a binary 2D array. 1 means the wall and 0 means
 * the empty space. You may assume that the borders of the maze are all walls.
 * The start and destination coordinates are represented by row and column
 * indexes.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input 1: a maze represented by a 2D array
 * 
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 * 
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (4, 4)
 * 
 * Output: 12
 * 
 * Explanation: One shortest way is : left -> down -> left -> down -> right ->
 * down -> right.
 * ⁠            The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input 1: a maze represented by a 2D array
 * 
 * 0 0 1 0 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 * 1 1 0 1 1
 * 0 0 0 0 0
 * 
 * Input 2: start coordinate (rowStart, colStart) = (0, 4)
 * Input 3: destination coordinate (rowDest, colDest) = (3, 2)
 * 
 * Output: -1
 * 
 * Explanation: There is no way for the ball to stop at the destination.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * There is only one ball and one destination in the maze.
 * Both the ball and the destination exist on an empty space, and they will not
 * be at the same position initially.
 * The given maze does not contain border (like the red rectangle in the
 * example pictures), but you could assume the border of the maze are all
 * walls.
 * The maze contains at least 2 empty spaces, and both the width and height of
 * the maze won't exceed 100.
 * 
 * 
 */
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	//Breadth first 
	//But this problem has a condition, the destination must be on the wall!! 
	//thus the next node should be go stragit forwrd to hit the wall the then back 1 
	//Distance is used instead of visited
	if(maze.empty()) return false;
	
	int m = maze.size();
	int n = maze[0].size();

	if(start[0] == destination[0] && start[1] == destination[1]) return true;
	
	if(start[0] < 0 || start[0] > m-1) return false;
	if(start[1] < 0 || start[1] > n-1) return false;
	if(destination[0] < 0 || destination[0] > m-1) return false;
	if(destination[1] < 0 || destination[1] > n-1) return false;

	//four directions
	int delta[] = {0, 1, 0, -1};
	//visited
	vector<vector<int>> d(m);
	for(auto dn = d.begin(); dn != d.end(); dn++)
        {
	    (*dn).resize(n, INT_MAX);
	}

	queue<pair<int, int>> q;
	pair<int, int> s(start[0], start[1]); //start node
	q.push(s);
	d[start[0]][start[1]] = 0;
	while(!q.empty())
	{
	    pair<int, int> node = q.front();
	    q.pop();
	    //check if we already reach the destination
	    //get to the adjacent nodes
	    for(int i = 0; i < 4; i++)
	    {
		int x = node.first + delta[i];
		int y = node.second + delta[(i+1)%4];
		int count = 0;
	
		//hit the wall!!
		while(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
		{
		    x += delta[i];
		    y += delta[(i+1)%4];
		    count++;
		}
		
		int px = x - delta[i];
		int py = y - delta[(i+1)%4];
		if(d[node.first][node.second] + count < d[px][py])
		{
		    d[px][py] = d[node.first][node.second] + count;
		    pair<int, int> next(px, py);
		    q.push(next);
		}
	    }
	}
	return d[destination[0]][destination[1]] == INT_MAX ? -1 :  d[destination[0]][destination[1]];
    }
};
