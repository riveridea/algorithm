/*
 * @lc app=leetcode id=356 lang=cpp
 *
 * [356] Line Reflection
 *
 * https://leetcode.com/problems/line-reflection/description/
 *
 * algorithms
 * Medium (30.51%)
 * Total Accepted:    17K
 * Total Submissions: 55.8K
 * Testcase Example:  '[[1,1],[-1,1]]'
 *
 * Given n points on a 2D plane, find if there is such a line parallel to
 * y-axis that reflect the given points.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[-1,1]]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[-1,-1]]
 * Output: false
 * 
 * 
 * Follow up:
 * Could you do better than O(n2) ?
 */
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
	//this is a math problem,
	//firstly find the possible reflction line by xr = (x_max + x_min)/2
	//then check each point (x1, y1) to see if it has a reflecting point (2*xr - x1, y1)
	set<pair<int, int>> pts;
	int x_max = INT_MIN, x_min = INT_MAX;
	for(auto p : points)
	{
	    x_max = max(x_max, p.first);
	    x_min = min(x_min, p.first);
	    pts.insert(p);
	}
	
	double xr = ((double)(x_max + x_min))/2;
	//valiate the reflection
	for(auto ps : pts)
	{
	    if(!pts.count({(int)(xr*2 - ps.first), ps.second}))
		return false;
	}
	return true;
    }
};
