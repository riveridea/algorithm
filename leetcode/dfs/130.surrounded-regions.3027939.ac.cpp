/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (20.98%)
 * Total Accepted:    118.9K
 * Total Submissions: 566.6K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if(m == 0) return; //return here, otherwise, if m=0, we can not access board[0]
	    int n = board[0].size();
	    if(n == 0) return;
        
        //search all the zeros connected to the board boundry.
	    for(int i=0; i<n; i++){
	        bfs(board, 0, i);
            bfs(board, m-1, i);
        }
        for(int j=1; j<m-1; j++){ //pay attention j = 1:m-2
            bfs(board, j, 0);
            bfs(board, j, n-1);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '+') board[i][j] = 'O';
            }
        }
    }
private:
    void bfs(vector<vector<char>> &board, int i, int j){
        queue<int> q;
        int n = board[0].size();
        visit(board, i, j, q);
        while(!q.empty()){
            //int cur = q.front(); q.pop();
            int x = q.front()/n;
            int y = q.front()%n;
            q.pop();
            visit(board, x-1, y, q);
            visit(board, x, y-1, q);
            visit(board, x+1, y, q);
            visit(board, x, y+1, q);
        }
    }
    void visit(vector<vector<char>> &board, int i, int j, queue<int> &q){
        int m = board.size();
	    int n = board[0].size();        
        if(i<0 || i >=m || j<0 || j>=n || board[i][j] != 'O') return;
        
        board[i][j] = '+';
        int point = i*n + j;
        q.push(point);
    }
};
