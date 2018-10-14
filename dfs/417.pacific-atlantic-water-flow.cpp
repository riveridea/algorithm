/*
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (35.46%)
 * Total Accepted:    32.7K
 * Total Submissions: 92.3K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * Example:
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 */
class Solution {
public:
    vector<pair<int, int>> res;
    vector<vector<int>> visited;

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
	//dfs, from 4 edges
	//for every point, dfs to its 4 neighbors
	//stop dfs if 
	//1. it is invalid point
	//2. if its value is less than its previous point, means current point cannot flow to pre
	//3. if it has been identifed as the answer - visited = 11 means connect to both oceans
	//4. if the current point has the same visited value with its pre, it means the curr has been
	//   traversed with the same visited scope, no need to do redundant traversal
	//3 & 4 means visisted[x][y] & previsited == previsited
	//
	//start dfs from 4 edgs, two edges have the same start visited value 
	//01 - pacific ocecn
	//10 - atlantic ocean
	
	if(matrix.empty()) return res;
	int m = matrix.size(), n = matrix[0].size();
	visited.resize(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
	    dfs(matrix, i, 0, INT_MIN, 1);     //bottom edge
	    dfs(matrix, i, n - 1, INT_MIN, 2); //up edge
	}
	for (int i = 0; i < n; i++)
	{
	    dfs(matrix, 0, i, INT_MIN, 1);      //left edge
	    dfs(matrix, m - 1, i, INT_MIN, 2);  //right edge 
	}
	return res;
    }

    void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int previsited)
    {
	//conditions to stop traversal
	if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()
	    || matrix[x][y] < pre || (visited[x][y] & previsited) == previsited)
	    return;

	visited[x][y] |= previsited;
	if(visited[x][y] == 3) 
	{
	    res.push_back({x, y});
	}
	dfs(matrix, x - 1, y, matrix[x][y], visited[x][y]);
	dfs(matrix, x + 1, y, matrix[x][y], visited[x][y]);
	dfs(matrix, x, y - 1, matrix[x][y], visited[x][y]);
	dfs(matrix, x, y + 1, matrix[x][y], visited[x][y]);
    }
};


