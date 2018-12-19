/*
 * @lc app=leetcode id=277 lang=cpp
 *
 * [277] Find the Celebrity
 *
 * https://leetcode.com/problems/find-the-celebrity/description/
 *
 * algorithms
 * Medium (35.02%)
 * Total Accepted:    68.1K
 * Total Submissions: 194.5K
 * Testcase Example:  '0 does not know 1; 1 does not know 0.'
 *
 * Suppose you are at a party with n people (labeled from 0 to n - 1) and among
 * them, there may exist one celebrity. The definition of a celebrity is that
 * all the other n - 1 people know him/her but he/she does not know any of
 * them.
 * 
 * Now you want to find out who the celebrity is or verify that there is not
 * one. The only thing you are allowed to do is to ask questions like: "Hi, A.
 * Do you know B?" to get information of whether A knows B. You need to find
 * out the celebrity (or verify there is not one) by asking as few questions as
 * possible (in the asymptotic sense).
 * 
 * You are given a helper function bool knows(a, b) which tells you whether A
 * knows B. Implement a function int findCelebrity(n), your function should
 * minimize the number of calls to knows.
 * 
 * Note: There will be exactly one celebrity if he/she is in the party. Return
 * the celebrity's label if there is a celebrity in the party. If there is no
 * celebrity, return -1.
 * 
 */
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
	//suppose a cadidate number result, start from 0, and check if it knows 
	//the 1, if knows, update the result to 1, and every time res knows i
	//update result as i until end, and in the second pass to verify if result 
	//does not know all the numbers but all the numbers know him
	int result = 0;	
	int i = 1;
	while(i < n)
	{
	    if(knows(result, i))
	    {
		result = i;
	    }
	    i++;
	}

	//verify
	for(int j = 0; j < n; j++)
	{
	    if(j != result)
	    {
		if(knows(result, j) || !knows(j, result))
		{
		    return -1;	
		}
	    }
	}
	return result;
    }
};
