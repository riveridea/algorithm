/*
 * @lc app=leetcode id=1066 lang=cpp
 *
 * [1066] Campus Bikes II
 *
 * https://leetcode.com/problems/campus-bikes-ii/description/
 *
 * algorithms
 * Medium (50.39%)
 * Total Accepted:    4.5K
 * Total Submissions: 9K
 * Testcase Example:  '[[0,0],[2,1]]\n[[1,2],[3,3]]'
 *
 * On a campus represented as a 2D grid, there are N workers and M bikes, with
 * N <= M. Each worker and bike is a 2D coordinate on this grid.
 * 
 * We assign one unique bike to each worker so that the sum of the Manhattan
 * distances between each worker and their assigned bike is minimized.
 * 
 * The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) =
 * |p1.x - p2.x| + |p1.y - p2.y|.
 * 
 * Return the minimum possible sum of Manhattan distances between each worker
 * and their assigned bike.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
 * Output: 6
 * Explanation: 
 * We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of
 * both assignments is 3, so the output is 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
 * Output: 4
 * Explanation: 
 * We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker
 * 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the
 * Manhattan distances as 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= workers[i][0], workers[i][1], bikes[i][0], bikes[i][1] < 1000
 * All worker and bike locations are distinct.
 * 1 <= workers.length <= bikes.length <= 10
 * 
 */
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
	//using dynamic programming, 
	//dp[i][s] - the minimum distance when the first i workers, the state s (mapping to if the jth bike selected)
	//start from the 1st worker, suppose the ith worker is added, we update the dp[i][s] by supposing the
	//the first (i-1) work does not use the jth bike
	
	int n = workers.size();
	int m = bikes.size();

	vector<vector<int>> dp(n+1, vector<int>(1<<m, INT_MAX));
	dp[0][0] = 0;

	int min_d = INT_MAX;
	//start dp
	for(int i = 1; i <= n; i++)
	{
	    //the first i workers
	    for(int s = 1; s < (1<<m); s++)
	    {
		//each state is mapping to the using or not using for all the bikes
		for (int j = 0; j < m; j++)
		{
		    if(s & (1<<j) == 0) continue;
		    //the jth bike is going to be used by the ith worker
		    //the prev state is just the jth bike not using
		    int prev = s ^ (1 <<j);
		    dp[i][s] = min(dp[i][s], dp[i-1][prev] + dis(workers[i-1], bikes[j]));
		    //don't forget to update min
		    if(i == n)
			min_d = min(min_d, dp[i][s]);
		}
	    }
	}
	return min_d;
    }

    int dis(const vector<int>& p1, const vector<int>& p2)
    {
	return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
