/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 *
 * https://leetcode.com/problems/paint-house/description/
 *
 * algorithms
 * Easy (49.91%)
 * Total Accepted:    60.6K
 * Total Submissions: 121.5K
 * Testcase Example:  '[[17,2,17],[16,16,5],[14,3,19]]'
 *
 * There are a row of n houses, each house can be painted with one of the three
 * colors: red, blue or green. The cost of painting each house with a certain
 * color is different. You have to paint all the houses such that no two
 * adjacent houses have the same color.
 * 
 * The cost of painting each house with a certain color is represented by a n x
 * 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color red; costs[1][2] is the cost of painting house 1 with color green, and
 * so on... Find the minimum cost to paint all houses.
 * 
 * Note:
 * All costs are positive integers.
 * 
 * Example:
 * 
 * 
 * Input: [[17,2,17],[16,16,5],[14,3,19]]
 * Output: 10
 * Explanation: Paint house 0 into blue, paint house 1 into green, paint house
 * 2 into blue. 
 * Minimum cost: 2 + 5 + 3 = 10.
 * 
 * 
 */
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
	//this is a dp problem, but please note there is restriction
	//that the adjacent houses cannot be painted with the same color
	//the first house, we have 3 solutions and just pick the cheapest
	//the next house, we will have dependency on the first one.
	//we have to check each color picked by the second house would rely
	//on the first house's color to generate the cheapest solution
	//if red, then we can only find red and blue chosen by the first house
	//thus for each color picked by the second house could be updated with
	//the cheapest cost
	//iterate this process until the final house, we get 3 color's solution
	//and finally select which is the cheapest
	
	int m = costs.size();
	if(m == 0) return 0;
	if(m == 1){
	    return *min_element(costs[0].begin(), costs[0].end());
	}

	for(int i = 1; i < m; i++){
	    costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
	    costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
	    costs[i][2] += min(costs[i-1][1], costs[i-1][0]);
	}
	
	return *min_element(costs[m-1].begin(), costs[m-1].end());
    }
};
















































