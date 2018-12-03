/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (41.17%)
 * Total Accepted:    89.1K
 * Total Submissions: 216.5K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 * 
 * Example:
 * 
 * 
 * Input: 
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output: 
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 * 
 * 
 */
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
	//to solve it in-place, we need to store the updated state to the higher bit of the 
	//element, the the lowest bit still have the original state
	//when output, just shift the higher state to the lowest state
	int m = board.size();
	if(m == 0) return;
	int n = board[0].size();
	if(n == 0) return;

	//go through all the elements and update the state to store it to higher bit 
	for(int i = 0; i < m; ++i)
	{
	    for(int j = 0; j < n; ++j)
	    {
		int count = 0; //count the number of 1 in its neighbours, including itself
		for(int k = max(i-1, 0); k < min(i+2, m); ++k)
		{
		    for(int l = max(j-1,0); l < min(j+2, n); ++l)  
		    {
			count += board[k][l] & 1;
		    }
		}
		//update the higher bit to 1, only with two conditions, all other conditions
		//will die, remember, count includes itself
		//1. exact 3 living leads to live
		//2. two or three living in neighbors lead to live
		if (count == 3 || count - board[i][j] == 3)
		{
		    board[i][j] |= 2;
		}
	    }
	}
	//output the result by shifting the higher bit
	for (int i = 0; i < m; i++)
	{
	    for (int j = 0; j < n; j++)
	    {
		board[i][j] >>= 1;
	    }
	}
    }
};



















