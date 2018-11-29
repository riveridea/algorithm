/*
 * @lc app=leetcode id=351 lang=cpp
 *
 * [351] Android Unlock Patterns
 *
 * https://leetcode.com/problems/android-unlock-patterns/description/
 *
 * algorithms
 * Medium (44.94%)
 * Total Accepted:    25.1K
 * Total Submissions: 55.9K
 * Testcase Example:  '1\n1'
 *
 * Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤
 * n ≤ 9, count the total number of unlock patterns of the Android lock screen,
 * which consist of minimum of m keys and maximum n keys.
 * 
 * 
 * 
 * Rules for a valid pattern:
 * 
 * 
 * Each pattern must connect at least m keys and at most n keys.
 * All the keys must be distinct.
 * If the line connecting two consecutive keys in the pattern passes through
 * any other keys, the other keys must have previously selected in the pattern.
 * No jumps through non selected key is allowed.
 * The order of keys used matters.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Explanation:
 * 
 * 
 * | 1 | 2 | 3 |
 * | 4 | 5 | 6 |
 * | 7 | 8 | 9 |
 * 
 * Invalid move: 4 - 1 - 3 - 6 
 * Line 1 - 3 passes through key 2 which had not been selected in the pattern.
 * 
 * Invalid move: 4 - 1 - 9 - 2
 * Line 1 - 9 passes through key 5 which had not been selected in the pattern.
 * 
 * Valid move: 2 - 4 - 1 - 3 - 6
 * Line 1 - 3 is valid because it passes through key 2, which had been selected
 * in the pattern
 * 
 * Valid move: 6 - 5 - 4 - 1 - 9 - 2
 * Line 1 - 9 is valid because it passes through key 5, which had been selected
 * in the pattern.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * Input: m = 1, n = 1
 * Output: 9
 * 
 * 
 * 
 */
class Solution {
public:
    int numberOfPatterns(int m, int n) {
	//this is not a dynamic programming,
	//this is more like a dfs 
	//thinkabout start from a specified point, all the next points could meet below possible conditions;
	//1. no middle 
	//2. middle exists but visited
	//3. middel exists and not visited
	//for 1 & 2, we have an valid next, but for 3, it is not valid next
	//recursive way, for each specific start, we find all possible combinations with len between m and n
	//also, the other trick is we only need to check 1, 2, 5, for 1 and 2 we have four symmetric solutions,
	//and for 5 it is unique
	//so, define a 9*9 table named jumps recoring the middle for each pair, like 1 and 3 has 2 as middle.
	//define a 1*9 table named visited
	int res = 0;
	vector<bool> v(10, false);
	vector<vector<int>> jumps(10, vector<int>(10, 0));
	jumps[1][3] = jumps[3][1] = 2;
	jumps[1][7] = jumps[7][1] = 4;
	jumps[1][9] = jumps[9][1] = 5;
	jumps[2][8] = jumps[8][2] = 5; 
	jumps[4][6] = jumps[6][4] = 5; 
	jumps[3][9] = jumps[9][3] = 6;
	jumps[3][7] = jumps[7][3] = 5;
	jumps[9][7] = jumps[7][9] = 8;
	
	res += dfs(1, 1, 0, m, n, jumps, v)*4;
	res += dfs(2, 1, 0, m, n, jumps, v)*4;
	res += dfs(5, 1, 0, m, n, jumps, v);

	return res;
    }
private:
    int dfs(int num, int len, int res, int m, int n, vector<vector<int>>& jumps, vector<bool>& visited)
    {
	//only len within range adds a pattern
	if(len >= m) ++res;
	++len; //a new num increases the length
	if(len > n) return res;

	//dfs to the next, all possible 9 next but 
	visited[num] = true; 
	for(int next = 1; next <= 9; ++next)
	{
	    int jump = jumps[num][next];
	    if(!visited[next] && (jump == 0 || visited[jump]))
	    {
		//actuall, each next return a new res and used by the next of the next loop
		//after all the loop done, the res collected the patterns of all the possible nexts 
		res = dfs(next, len, res, m, n, jumps, visited);
	    }
	}
	//must resume to false for other traversal
	visited[num] = false;
	return res;
    }
};





