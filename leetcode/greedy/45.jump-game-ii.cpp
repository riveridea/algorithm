/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.60%)
 * Total Accepted:    140.6K
 * Total Submissions: 528.4K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.



	// let us try
	⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */
class Solution {
public:
    int jump(vector<int>& nums) {
	//let us try greedy algorithm
	int n = nums.size();
	if(n <= 1) return 0;

	//this greedy is hard to understand
	//but lastReach is the when you reach pos i, the last Maximum reachable
	//current reach is the updated when you are at pos, currReach = max(i + nums[i], currReach)
	//The MOST IMPORTANT THING in this problem is all the index is reachable, there is no 0
	//so we scan the point between the current i and curreReach to update the currReach
	//during the scan, we understand there is must be a step before hit the currReach on the first i
	//but we DONT record the actually next point is, though is within this range
	//once the i is greater than LastReach(currReach for first i), we will see if there is new currReach
	//greater than the lastReach, if NOT, then we cannot get destination.
	//if yes, we have a new i and new lastReach(the currReach as i) and will update the currReach a one by one
	//during the new Range, between new i and new lastReach
	//So lastReach is the end of the last range, i is scanned before lastReach, currReach is used 
	//to find the new maximal Reachable
	int lastReach = 0;
	int currReach = 0;
	int step = 0;
	for (int i = 0; i < nums.size(); i++)
	{
	    //cout << i << "?" << lastReach;
	    if (i > lastReach)  // the key is to scann every one before lastReach
	    {
		if(currReach > lastReach) //only if new currReach is greater than lastReach then there must be a new step
		{
		    step++;
		    lastReach = currReach;
		}
		else
		    return 0;
	    }

	    currReach = max(i+nums[i], currReach);
	    
	    //already reachable to the destination, no need to go to next loop
	    if(currReach >= nums.size()-1) return step+1;
	}
    }
};
