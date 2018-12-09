/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (30.59%)
 * Total Accepted:    212.7K
 * Total Submissions: 695.4K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
	//this is pretty interesting problem if you understand a bottom up dynamic programming
	//in which you get the unknown from the known answser and elimiate the recursion
	//the first the known thing is the right most (dest) is definitily GOOD point to reach 
	//the destination, then iteratet from the right to the left until the very start, you will 
	//know if it is GOOD or UNKNOWN point, very intuitive.
	//0: unknown
	//1: BAD
	//2: GOOD

	int n = nums.size();
	vector<int> stat(n, 0); //initialized as all unknown;
	stat[n-1] = 2; //the last one musht be GOOD
	
	for(int i = n -2; i >= 0; i--)
	{
	    //let us try all the possible moves at position i
	    int walk_dst = min(i+nums[i], n-1); //the farest possible this walk
	    //try the 1 by 1
	    bool isgood = false;
	    for(int j = 1; j < walk_dst - i + 1; j++)
	    {
		if(stat[i + j] == 2) // on the path, at least on
		{
		    stat[i] = 2;
		    isgood = true;
		    break;
		}
	    }

	    //no path to GOOD is found
	    stat[i] = isgood ? 2 : 1; //BAD
	}

	return stat[0] == 2;
    }
};











