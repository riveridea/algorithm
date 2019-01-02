/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 *
 * https://leetcode.com/problems/battleships-in-a-board/description/
 *
 * algorithms
 * Medium (64.64%)
 * Total Accepted:    54.4K
 * Total Submissions: 84.1K
 * Testcase Example:  '[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]'
 *
 * Given an 2D board, count how many battleships are in it. The battleships are
 * represented with 'X's, empty slots are represented with '.'s. You may assume
 * the following rules:
 * 
 * 
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words,
 * they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1
 * column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships -
 * there are no adjacent battleships.
 * 
 * 
 * Example:
 * X..X
 * ...X
 * ...X
 * 
 * In the above board there are 2 battleships.
 * 
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 * 
 * This is an invalid board that you will not receive - as battleships will
 * always have a cell separating between them.
 * 
 * Follow up:Could you do it in one-pass, using only O(1) extra memory and
 * without modifying the value of the board?
 */
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
	//the problem only gives you valid board
	//you just need to count the head of each battle ship, which means the 
	//point is x and its predecor in row and col are not x, or it is the board[0][0]
	if(board.empty()) return 0;

	int cnt = 0;
	int rlen = board.size();
	int clen = board[0].size();
	for(int i = 0; i < rlen; i++)
	{
	    for(int j = 0; j < clen; j++)
	    {
		/*
		if(board[i][j] == 'X' )
		{
		    if((i == 0 || board[i-1][j] != 'X') && (j == 0 || board[i][j-1] != 'X'))
			cnt++;
		}
		*/

		cnt += board[i][j] == 'X' && (i == 0 || board[i-1][j] != 'X') && (j == 0 || board[i][j-1] != 'X');
	    }
	}
	return cnt;
    }
};











