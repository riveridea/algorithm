/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 *
 * https://leetcode.com/problems/bulb-switcher/description/
 *
 * algorithms
 * Medium (43.46%)
 * Total Accepted:    54.5K
 * Total Submissions: 125.4K
 * Testcase Example:  '3'
 *
 * There are n bulbs that are initially off. You first turn on all the bulbs.
 * Then, you turn off every second bulb. On the third round, you toggle every
 * third bulb (turning on if it's off or turning off if it's on). For the i-th
 * round, you toggle every i bulb. For the n-th round, you only toggle the last
 * bulb. Find how many bulbs are on after n rounds.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 1 
 * Explanation: 
 * At first, the three bulbs are [off, off, off].
 * After first round, the three bulbs are [on, on, on].
 * After second round, the three bulbs are [on, off, on].
 * After third round, the three bulbs are [on, off, off]. 
 * 
 * So you should return 1, because there is only one bulb is on.
 * 
 * 
 */
class Solution {
public:
    int bulbSwitch(int n) {
	//this is a pure math problem!!!
	//explanation: only the number of square less or equal n
	//becuase only square number has odd number of factors,
	//each factor means a round of switching, because the expect the 
	//squrae root, all are the pair of factors
	//the problem is going to find how many squres less or eqaul than n
	int i = 1;
	for(;i*i <= n; i++);
	return i-1;
    }
};
