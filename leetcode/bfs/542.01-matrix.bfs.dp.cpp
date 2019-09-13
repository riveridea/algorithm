/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (36.71%)
 * Total Accepted:    52.7K
 * Total Submissions: 143.5K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * 
 * Example 1: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[0,0,0]]
 * 
 * Output:
 * [[0,0,0],
 * [0,1,0],
 * [0,0,0]]
 * 
 * 
 * Example 2: 
 * 
 * 
 * Input:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,1,1]]
 * 
 * Output:
 * [[0,0,0],
 * ⁠[0,1,0],
 * ⁠[1,2,1]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of elements of the given matrix will not exceed 10,000.
 * There are at least one 0 in the given matrix.
 * The cells are adjacent in only four directions: up, down, left and right.
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
	//come on let's do BFS 
	//start from each 0!!!
	//then we update each's dist only if the new dist needs to be updated!
	int m = matrix.size();
	int n = matrix[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
	queue<vector<int>> q;

	//step 1, initialize all the 0' dist as 0
	for(int i = 0; i < m; i++){
	    for(int j = 0; j < n; j++){
		if(matrix[i][j] == 0)
		{
		    dist[i][j] = 0;
		    q.push({i, j});
		}
	    }
	}

	//step 2, start BFS, update dist for each point
	int dr[] = {1, 0, -1, 0};
	int dc[] = {0, 1, 0, -1};
	while(!q.empty()){
	    vector<int> p = q.front(); q.pop();
	    int r = p[0];
	    int c = p[1];
	    for(int i = 0; i < 4; i++){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr >= 0 && nc >= 0 && nr < m && nc < n)
		{
		    if(dist[nr][nc] > dist[r][c] + 1){
			dist[nr][nc] = dist[r][c] + 1;
			q.push({nr, nc});
		    }
		}
	    }
	}	
	return dist;
    }
};






































