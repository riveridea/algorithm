/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (40.07%)
 * Total Accepted:    189.4K
 * Total Submissions: 472.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
	//this problem is not complex in idea, just pay attenion the detail
	bool used[9]; //store the status for each digit
	
	//check each row and column find if duplicate exist
	for(int i = 0; i < 9; i++)
	{
	    //check row
	    fill(used, used+9, false);
	    for(int j = 0; j < 9; j++)
	    {
		if(!check(board[i][j], used))
		    return false;
	    }

	    //check column
	    fill(used, used+9, false);
	    for(int j = 0; j < 9; j++)
	    {
		if(!check(board[j][i], used))
		    return false;
	    }
	}

	//check the 9 sub-box of each 3x3
	for(int r = 0; r < 3; r++)	
	{
	    for(int c = 0; c < 3; c++)
	    {
		//check each sub-box
		fill(used, used+9, false);
		for(int i = r*3; i < r*3 + 3; i++)
		{
		    for(int j = c*3; j < c*3 + 3; j++)
		    {
			if(!check(board[i][j], used))
			    return false;
		    }
		}
	    }
	}

	return true;
    }

private:
    //check if the ch is already in
    bool check(char ch, bool used[9])
    {
	if(ch == '.') return true;	
	
	if(used[ch - '1']) return false;
	else
	    return (used[ch - '1'] = true);//mark it as used
    }
};
