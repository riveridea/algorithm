/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 *
 * https://leetcode.com/problems/elimination-game/description/
 *
 * algorithms
 * Medium (43.03%)
 * Total Accepted:    20.6K
 * Total Submissions: 47.9K
 * Testcase Example:  '9'
 *
 * 
 * There is a list of sorted integers from 1 to n. Starting from left to right,
 * remove the first number and every other number afterward until you reach the
 * end of the list.
 * 
 * Repeat the previous step again, but this time from right to left, remove the
 * right most number and every other number from the remaining numbers.
 * 
 * We keep repeating the steps again, alternating left to right and right to
 * left, until a single number remains.
 * 
 * Find the last number that remains starting with a list of length n.
 * 
 * Example:
 * 
 * Input:
 * n = 9,
 * 1 2 3 4 5 6 7 8 9
 * 2 4 6 8
 * 2 6
 * 6
 * 
 * Output:
 * 6
 * 
 * 
 */
class Solution {
public:
    int lastRemaining(int n) {
	//this is a tricky math problem actaully         
	//res is interatively to move forward based on the step
	//for remaining elements with odd number, the first remained element would
	//be eleminated from the right to left, if even, then keep the first element
	int step = 1;
	int res = 1;
	while(step*2 <= n)
	{
	    res += step;
	    step *= 2;
	    if(step*2 > n) break;
	    if((n/step)%2 == 1) res += step;
	    step *= 2;
	}
	return res;
    }
};



































