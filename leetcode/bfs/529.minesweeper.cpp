/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 *
 * https://leetcode.com/problems/minesweeper/description/
 *
 * algorithms
 * Medium (50.62%)
 * Total Accepted:    25.1K
 * Total Submissions: 49.6K
 * Testcase Example:  '[["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]]\n[3,0]'
 *
 * Let's play the minesweeper game (Wikipedia, online game)!
 * 
 * You are given a 2D char matrix representing the game board. 'M' represents
 * an unrevealed mine, 'E' represents an unrevealed empty square, 'B'
 * represents a revealed blank square that has no adjacent (above, below, left,
 * right, and all 4 diagonals) mines, digit ('1' to '8') represents how many
 * mines are adjacent to this revealed square, and finally 'X' represents a
 * revealed mine.
 * 
 * Now given the next click position (row and column indices) among all the
 * unrevealed squares ('M' or 'E'), return the board after revealing this
 * position according to the following rules:
 * 
 * 
 * If a mine ('M') is revealed, then the game is over - change it to 'X'.
 * If an empty square ('E') with no adjacent mines is revealed, then change it
 * to revealed blank ('B') and all of its adjacent unrevealed squares should be
 * revealed recursively.
 * If an empty square ('E') with at least one adjacent mine is revealed, then
 * change it to a digit ('1' to '8') representing the number of adjacent
 * mines.
 * Return the board when no more squares will be revealed.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * [['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'M', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E'],
 * ⁠['E', 'E', 'E', 'E', 'E']]
 * 
 * Click : [3,0]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'M', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Click : [1,2]
 * 
 * Output: 
 * 
 * [['B', '1', 'E', '1', 'B'],
 * ⁠['B', '1', 'X', '1', 'B'],
 * ⁠['B', '1', '1', '1', 'B'],
 * ⁠['B', 'B', 'B', 'B', 'B']]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The range of the input matrix's height and width is [1,50].
 * The click position will only be an unrevealed square ('M' or 'E'), which
 * also means the input board contains at least one clickable square.
 * The input board won't be a stage when game is over (some mines have been
 * revealed).
 * For simplicity, not mentioned rules should be ignored in this problem. For
 * example, you don't need to reveal all the unrevealed mines when the game is
 * over, consider any cases that you will win the game or flag any squares.
 * 
 * 
 */
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
	//trying the BFS
	int m = board.size();
	if (m == 0) return board;
	int n = board[0].size(); 
	if (n == 0) return board;	

	if(click[0] < 0 || click[0] >= m || click[1] < 0 || click[1] >= n) return board;
    
	//eight directions
	int d[8][2] = {{0,1}, {0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
	pair<int, int> s(click[0], click[1]);
	queue<pair<int, int>> q;
	if(board[s.first][s.second] == 'M')
	{
	    board[s.first][s.second] = 'X';
	    return board;
	}
	q.push(s);
	while(!q.empty())
	{
	    pair<int, int> node = q.front(); 
	    q.pop();

	    int cx = node.first;
	    int cy = node.second;
	  
	    if(board[cx][cy] != 'E') continue;
	    //check the adjacent positions
	    int count = 0; //check number of mines in adjacents
	    for(int i = 0; i < 8; i++)
	    {
		int x = cx + d[i][0];
		int y = cy + d[i][1];
		
		if(x < 0 || x >= m || y < 0 || y >= n) continue;
		if(board[x][y] == 'M') count++;
	    }
	    //only go further reavling for no adjacent M is revealed
	    if(count == 0)
	    {
		board[cx][cy] = 'B';
		for(int i = 0; i < 8; i++)
		{
		    int x = cx + d[i][0];
		    int y = cy + d[i][1];
		    if(x < 0 || x >= m || y < 0 || y >= n) continue;
		    if(board[x][y] == 'M' || board[x][y] == 'E')
		    {
			q.push(pair<int, int>(x, y));
		    }
		}
	    }
	    else
	    {
		board[cx][cy] = '0' + count;
	    }
	}	
	
	return board;
    }
};























