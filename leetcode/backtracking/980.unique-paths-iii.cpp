/*
 * [1022] Unique Paths III
 *
 * https://leetcode.com/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (71.56%)
 * Total Accepted:    16.8K
 * Total Submissions: 23.5K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * On a 2-dimensional grid, there are 4 types of squares:
 * 
 * 
 * 1 represents the starting square.  There is exactly one starting square.
 * 2 represents the ending square.  There is exactly one ending square.
 * 0 represents empty squares we can walk over.
 * -1 represents obstacles that we cannot walk over.
 * 
 * 
 * Return the number of 4-directional walks from the starting square to the
 * ending square, that walk over every non-obstacle square exactly once.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * Output: 2
 * Explanation: We have the following two paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * Output: 4
 * Explanation: We have the following four paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,1],[2,0]]
 * Output: 0
 * Explanation: 
 * There is no path that walks over every empty square exactly once.
 * Note that the starting and ending square can be anywhere in the
 * grid.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length * grid[0].length <= 20
 * 
 */
class Solution {
public:
	int ex;
	int ey;
	int sx;
	int sy;
	int empty;
	int res;
    int uniquePathsIII(vector<vector<int>>& grid) {
	    //damn it I need more practice of bactracking!!!
	    int m = grid.size();
	    if(!m) return 0;
	    int n = grid[0].size();
	    if(!n) return 0;

	    //we need find the start point and end point firstly
	    empty = 1; //including starting 
	    for(int i = 0; i < m; i++){
	        for(int j = 0; j < n; j++){
	    	    if(grid[i][j] == 0){
	    	        empty++;
	    	    }
	    	    else if(grid[i][j] == 1){
	    	        sx = i;
	    	        sy = j;
	    	    }
	    	    else if(grid[i][j] == 2){
	    	        ex = i;
	    	        ey = j;
	    	    }
	        }
	    }

		//now we do recursive DFS, also need to backtracking 
		dfs(grid, sx, sy);
		return res;

    }
private:
	void dfs(vector<vector<int>>& grid, int x, int y){
		if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() ||
			grid[x][y] < 0) 
			return;
		if(x == ex && y == ey){
			if(empty == 0) res++;
			return;
		}

		//dfs to the nexts, remember backtracking after nexts are processed!!
		grid[x][y] = -2;
		empty--;
		dfs(grid, x, y+1);
		dfs(grid, x, y-1);
		dfs(grid, x-1, y);
		dfs(grid, x+1, y);
		grid[x][y] = 0;
		empty++;
	}
};
