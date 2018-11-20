/*
 * [490] The Maze
 *
 * https://leetcode.com/problems/the-maze/description/
 *
 * algorithms
 * Medium (45.09%)
 * Total Accepted:    23.8K
 * Total Submissions: 52.8K
 * Testcase Example:  '[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]\n[0,4]\n[4,4]'
 *
 * There is a ball in a maze with empty spaces and walls. The ball can go
 * through empty spaces by rolling up, down, left or right, but it won't stop
 * rolling until hitting a wall. When the ball stops, it could choose the next
 * direction.
 * 
 * Given the ball's start position, the destination and the maze, determine
 * whether the ball could stop at the destination.
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
 * Output: true
 * 
 * Explanation: One possible way is : left -> down -> left -> down -> right ->
 * down -> right.
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
 * Output: false
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
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	//Breadth first 
	//But this problem has a condition, the destination must be on the wall!! 
	//thus the next node should be go stragit forwrd to hit the wall the then back 1 
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
	vector<vector<int>> v(m);
	for(auto vn = v.begin(); vn != v.end(); vn++)
        {
	    (*vn).resize(n, 0);
	}

	queue<pair<int, int>> q;
	pair<int, int> s(start[0], start[1]); //start node
	q.push(s);
	v[start[0]][start[1]] = 1;
	while(!q.empty())
	{
	    pair<int, int> node = q.front();
	    q.pop();
	    //check if we already reach the destination
	    //get to the adjacent nodes
	    if(node.first == destination[0] && node.second == destination[1]) return true;
	    for(int i = 0; i < 4; i++)
	    {
		int x = node.first + delta[i];
		int y = node.second + delta[(i+1)%4];
	
		//hit the wall!!
		while(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
		{
		    x += delta[i];
		    y += delta[(i+1)%4];
		}
		
		int px = x - delta[i];
		int py = y - delta[(i+1)%4];
	
		if(v[px][py] == 0)
		{
		    pair<int, int> next(px, py);
		    q.push(next);
		    v[px][py] = 1; 
		}
	    }
	}
	return false;
    }
};
