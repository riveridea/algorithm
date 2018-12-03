/*
 * @lc app=leetcode id=294 lang=cpp
 *
 * [294] Flip Game II
 *
 * https://leetcode.com/problems/flip-game-ii/description/
 *
 * algorithms
 * Medium (47.37%)
 * Total Accepted:    39.4K
 * Total Submissions: 83.1K
 * Testcase Example:  '"++++"'
 *
 * You are playing the following Flip Game with your friend: Given a string
 * that contains only these two characters: + and -, you and your friend take
 * turns to flip two consecutive "++" into "--". The game ends when a person
 * can no longer make a move and therefore the other person will be the
 * winner.
 * 
 * Write a function to determine if the starting player can guarantee a win.
 * 
 * Example:
 * 
 * 
 * Input: s = "++++"
 * Output: true 
 * Explanation: The starting player can guarantee a win by flipping the middle
 * "++" to become "+--+".
 * 
 * 
 * Follow up:
 * Derive your algorithm's runtime complexity.
 * 
 */
class Solution {
public:
    bool canWin(string s) {
	//recursive backtracking
	//think about canWin is for a user, no matter the user is first one or
	//the second one, return true means the user canWin but false means the user 
	//cannot win
	//so the target is for the top level recurision, if the user can find a solution
	//to make the sencod user when calling canWin fails, the first user definelty win
	//or, if there is no avaible solution for current user, return false
	
	if(s.size() == 0) return false;

	for(int i = 0; i < s.size() - 1; i++)
	{
	    //find availble move
	    if (s[i] == '+' && s[i+1] == '+')
	    {
		//doing move
		s[i] = '-';
		s[i+1] = '-';
		if(!canWin(s)) //next user cannot win, so the current user win
		{
		    return true;	
		}
		//next user can win, so try next possible move testing if can win
		s[i] = '+';
		s[i+1] = '+';
	    }
	}

	return false;
    }
};
















