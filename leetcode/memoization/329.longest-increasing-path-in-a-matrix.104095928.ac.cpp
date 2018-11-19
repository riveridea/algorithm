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
