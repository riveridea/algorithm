/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 *
 * https://leetcode.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (28.40%)
 * Total Accepted:    24.5K
 * Total Submissions: 86.2K
 * Testcase Example:  '3\n5\n4'
 *
 * You are given two jugs with capacities x and y litres. There is an infinite
 * amount of water supply available. You need to determine whether it is
 * possible to measure exactly z litres using these two jugs.
 * 
 * If z liters of water is measurable, you must have z liters of water
 * contained within one or both buckets by the end.
 * 
 * Operations allowed:
 * 
 * 
 * Fill any of the jugs completely with water.
 * Empty any of the jugs.
 * Pour water from one jug into another till the other jug is completely full
 * or the first jug itself is empty.
 * 
 * 
 * Example 1: (From the famous "Die Hard" example)
 * 
 * 
 * Input: x = 3, y = 5, z = 4
 * Output: True
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = 2, y = 6, z = 5
 * Output: False
 * 
 */
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
	//this is a pure math problem, think about a new jug, we have m times x operations, n times y operation,
	//m and n are integers, negative means empty, positive means full, for example, if x is graetery than y
	//then full x and pour x to y until y is full, this is actually x - y, m = 1, n = -1
	//for an equation m*x + n*y = d, it has a solution if and only if d is gcd(x, y) and its multiples.
	//so if z%gcd(x,y), there must be m and n. to satisify m*x + n*y = z. 
	//Also, note, x + y should be no less than z, otherwise you cannot get the final measured z in x and y together
	if(z == 0) return true; // 0%any int is 0

	if((long)(x+y) < z) return false;

	return z%gcd(x,y) == 0;
     }
private:
    int gcd(int x, int y)
    {
	return y == 0 ? x : gcd(y, x%y);
    }
};




























