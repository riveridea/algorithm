/*
 * @lc app=leetcode id=265 lang=cpp
 *
 * [265] Paint House II
 *
 * https://leetcode.com/problems/paint-house-ii/description/
 *
 * algorithms
 * Hard (42.37%)
 * Total Accepted:    48.3K
 * Total Submissions: 114K
 * Testcase Example:  '[[1,5,3],[2,9,4]]'
 *
 * There are a row of n houses, each house can be painted with one of the k
 * colors. The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the
 * same color.
 * 
 * The cost of painting each house with a certain color is represented by a n x
 * k cost matrix. For example, costs[0][0] is the cost of painting house 0 with
 * color 0; costs[1][2] is the cost of painting house 1 with color 2, and so
 * on... Find the minimum cost to paint all houses.
 * 
 * Note:
 * All costs are positive integers.
 * 
 * Example:
 * 
 * 
 * Input: [[1,5,3],[2,9,4]]
 * Output: 5
 * Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum
 * cost: 1 + 4 = 5; 
 * Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 +
 * 2 = 5. 
 * 
 * 
 * Follow up:
 * Could you solve it in O(nk) runtime?
 * 
 */
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
	//dp, as k >> 3, we cannot use the soluiton used for paint house 1.
	//use a dp[i][j] to represent the minimum cost at house i if color j is chosen
	//need a min1 and min2 as the color id at last house with minimum cost and second
	//minimum color id
	//at pos i, we just try ever color j
	//if j is equal to min1, we update the dp[i][j] using the min2(cached with last2)
	//if j is not equal to min1, so min1(cached by last1) 
	//so, each step traversing each house, needs to update
	//dp[i][j], and min1, min2
	int m = costs.size();
	if(m == 0) return 0;
	int n = costs[0].size();
	if (n == 0) return 0;

	vector<vector<int>> dp = costs;
	int min1 = -1, min2 = -1;
	for(int i = 0; i < m; i++){
	    int last1 = min1, last2 = min2; //min1 and min2 of last house
	    min1 = -1; min2 = -1; //used to cache the min1 and min2 for current house
	    for(int j = 0; j < n; j++){
		if(j == last1){
		    dp[i][j] += last2 < 0 ? 0 : dp[i-1][last2];
		}
		else{
		    dp[i][j] += last1 < 0 ? 0 : dp[i-1][last1];
		}

		//update min1 and min2 if necessary
		if(min1 < 0 || dp[i][j] < dp[i][min1]){
		    min2 = min1;
		    min1 = j;
		}
		else if(min2 < 0 || dp[i][j] < dp[i][min2]){
		    min2 = j;
		}
	    }
	}
	return dp[m-1][min1];
    }
};
