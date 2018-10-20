/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (29.11%)
 * Total Accepted:    214.5K
 * Total Submissions: 736.7K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if (dfs(board, 0, i, j, word, visited))
                    return true; //once got a solution, just return
            }
        }
        
        return false; //no sultion found
    }
    bool dfs(vector<vector<char> > &board, int index, int x, int y, string word, vector<vector<bool> > &visited){
        if(index == word.size()) return true;
        //this boundary check should be first, otherwise will cause segment fault in the folowing array access!
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if(board[x][y] != word[index]) return false;
        if(visited[x][y]) return false; //already visited 
        
        visited[x][y] = true;
        bool ret = dfs(board, index+1, x-1, y, word, visited) ||
                   dfs(board, index+1, x+1, y, word, visited) ||
                   dfs(board, index+1, x, y-1, word, visited) ||
                   dfs(board, index+1, x, y+1, word, visited);
        visited[x][y] = false;
        
        return ret;
    }
};
