/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 *
 * https://leetcode.com/problems/minimum-area-rectangle/description/
 *
 * algorithms
 * Medium (50.97%)
 * Total Accepted:    22.6K
 * Total Submissions: 44.4K
 * Testcase Example:  '[[1,1],[1,3],[3,1],[3,3],[2,2]]'
 *
 * Given a set of points in the xy-plane, determine the minimum area of a
 * rectangle formed from these points, with sides parallel to the x and y
 * axes.
 * 
 * If there isn't any rectangle, return 0.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= points.length <= 500
 * 0 <= points[i][0] <= 40000
 * 0 <= points[i][1] <= 40000
 * All points are distinct.
 * 
 * 
 * 
 */
class Solution {
#define UPD 40001
public:
    int minAreaRect(vector<vector<int>>& points) {
	//firstly try the brute force but count based on diagol
	unordered_set<int> s;  //key will be based on 40001*x + y
	int res = INT_MAX;
	for(const vector<int>& p : points)
	{
	    int k = UPD*p[0] + p[1];
	    for(int e : s)
	    {
		//check diagnol
		if(k == e) continue;
		vector<int> pd({e/UPD, e%UPD});
		int pu = UPD*p[0] + pd[1];
		int pl = UPD*pd[0] + p[1];
		if(s.find(pu) != s.end() && s.find(pl) != s.end())
		{
		    int area = abs(p[0] - pd[0]) * abs(p[1] - pd[1]);
		    if(area > 0 && area < res)
			res = area;
		}
	    }
	    s.insert(k);
	}

	return res < INT_MAX ? res : 0;
    }
};
