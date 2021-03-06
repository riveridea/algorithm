/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (34.38%)
 * Total Accepted:    109.4K
 * Total Submissions: 318.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
	//iteravtive backtracking, put all the positions of the '.' to the vector 
	//then go thorugh every one of the vector to find a valid solution(0 - 9) at this 
	//point, if found, place this solution to board[r][c] and go to check next
	//if not found at this point, then backtrack to its previous one in the vector,
	//while reset the board[r][c] to '.'
	//the hard thing is the index computation of the checkPoint(r, c) within of the same
	//3*3 grid group.
	if(board.empty()) return;
	vector<int> bp; //store the positions of 
	for(int i = 0; i < 9; i++)
	    for(int j = 0; j < 9; j++)
	    {
		if(board[i][j] == '.')
		{
		    bp.push_back(i*9 + j);  
		}
	    }
	
	//traversal every '.' point to find solutions
	int len = bp.size();
	int i = 0;
	while(i < len) //use while because i could be backtracked	
	{
	    int index = bp[i];
	    int row = index/9;
	    int col = index%9;

	    //cout << "i<<" <<i << ":";
	    //check if what the current point value is
	    //step forward as the current point value has been checked
	    char c;
	    //cout << "board["<< row << "][" << col << "]=" << board[row][col] << ">"; 
	    if(board[row][col] == '.')
		c = '1'; //start from 1
	    else
		c = board[row][col] + 1; //try the next one, may be here due to backtrack
	    
	    while(c < '9' + 1)
	    {
	        //cout << c << ".";
		if(checkPoint(board, row, col, c) == false)
		{
		    c++;
		    continue;
		}

		//find a candidated solution at the time
		board[row][col] = c;	
		break;
	    }

	    //see if we go forward or backtrack
	    if(c >= '9' + 1)
	    {
		//cannot find any candidates at this point,
		//needs to backtrack to its previous '.'
		i--;
		board[row][col] = '.'; //reset the current node, but do note its previous may be some value other than '.', that
				       // is the reason of line 76 - 79
	    }
	    else
	    {
		//move forward to next '.'
		i++;
	    }
	    //cout << "i->" << i << endl;
	}
    }
private:
    bool checkPoint(vector<vector<char>>& board, int row, int col, char val)
    {
	//please note, when calling checkPoing, val is not put into this board[row][col] yet
	for(int i = 0; i < 9; i++)
	{
	    if(board[row][i] == val)
		return false;
	    if(board[i][col] == val)
		return false;
	    if(board[row - row%3 + i/3][col - col%3 + i%3] == val)
		return false;
	}
	return true;
    }
};
