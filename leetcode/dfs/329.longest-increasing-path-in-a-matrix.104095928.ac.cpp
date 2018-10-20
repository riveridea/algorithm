/*
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (37.97%)
 * Total Accepted:    65.2K
 * Total Submissions: 171.6K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 * 
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * Output: 4 
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 * 
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //looks like use the DP with recursion can solve this problem
        //choose the max value from the right/left/up/down
        if(matrix.empty()) return 0;

        row_size = matrix.size();
        col_size = matrix[0].size();
        distance.resize(row_size, vector<int>(col_size));
        
        int max_len = 0;
        for(int i = 0; i < row_size; i++)
            for(int j = 0; j < col_size; j++)
            {
                int rc = find_lip(matrix, INT_MIN, i, j);
                max_len = max(max_len, rc);
            }
        
        return max_len;
    }
private:
    int find_lip(vector<vector<int>>& matrix, int cur, int i, int j)
    {
        if(i < 0 || i >= row_size || j < 0 || j >= col_size)
            return 0;
        if(cur >= matrix[i][j])
            return 0;
            
        if(distance[i][j] > 0) //already computed for this node
            return distance[i][j];
        
        //now do the dp
        int r = find_lip(matrix, matrix[i][j], i, j+1);
        int l = find_lip(matrix, matrix[i][j], i, j-1);
        int u = find_lip(matrix, matrix[i][j], i-1, j);
        int d = find_lip(matrix, matrix[i][j], i+1, j);
        
        distance[i][j] = max(r, max(l, max(u, d))) + 1;
        return distance[i][j];
    }
    
    int row_size = 0;
    int col_size = 0;
    vector<vector<int>> distance;    
};
