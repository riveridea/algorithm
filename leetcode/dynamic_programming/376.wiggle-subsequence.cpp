/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (36.60%)
 * Total Accepted:    41.2K
 * Total Submissions: 112.7K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The
 * first difference (if one exists) may be either positive or negative. A
 * sequence with fewer than two elements is trivially a wiggle sequence.
 * 
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
 * (6,-3,5,-7,3) are alternately positive and negative. In contrast,
 * [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
 * first two differences are positive and the second because its last
 * difference is zero.
 * 
 * Given a sequence of integers, return the length of the longest subsequence
 * that is a wiggle sequence. A subsequence is obtained by deleting some number
 * of elements (eventually, also zero) from the original sequence, leaving the
 * remaining elements in their original order.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is
 * [1,17,10,13,10,16,8].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * Follow up:
 * Can you do it in O(n) time?
 * 
 * 
 * 
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
	//this problem is a DP, but i feel hard when only define a dp[i] as the longest wiggle seqence ending
	//at nums[i] becuase you don't know if the sequence is down or up at this postion and don't know if
	//if the nums[i] is included in the sequence
	
	//The idea is to define up[i] and down[i]
	//up[i] is the longest wiggele sequence with the last two elements difference as positive, but not necessary ending at i
	//down[i] is the longest wiggele sequence with the last two elements difference as negative, but not necessary ending at i
	//will udpate up[i] and down[i] accorinding to the nums[i] and nums[i-1] and finally select the maximum of (up[nums.size() -1], 
	//down[nums.size()-1])
	int n = nums.size();
	if (n == 0) return 0;
	vector<int> up(n, 0);
	vector<int> down(n, 0);
	
	up[0] = 1;
	down[0] = 1;
	
	for(int i = 1; i < n; i++)
	{
	    if(nums[i] > nums[i-1])
	    {
		up[i] = down[i-1] + 1;
		down[i] = down[i-1];
	    }
	    else if (nums[i] < nums[i-1])
	    {
		down[i] = up[i-1] + 1;
		up[i] = up[i-1];
	    }
	    else
	    {
		up[i] = up[i-1];
		down[i] = down[i-1];
	    }
	}
	return max(up[n-1], down[n-1]);
    }
};






























