/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (42.23%)
 * Total Accepted:    305.2K
 * Total Submissions: 722.6K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */
class Solution {
public:
    int climbStairs(int n) {
        //suppose the f[n] represents the possible distinct ways to climb to the n steps
        //then f[n] = f[n-1] + f[n-2] (advance one step from n-1 step or n-2 step)
        //this problem becomes fibonacci sequence
        int a=1, b = 1;
        for(int i=2; i<=n; i++){
            int next = b;
            b += a;;
            a = next;
        }
        return b;
    }
};
