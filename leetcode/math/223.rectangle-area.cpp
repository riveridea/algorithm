/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (35.06%)
 * Total Accepted:    80.5K
 * Total Submissions: 229.5K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note:
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	//this problem the key is to determine if two rectagule is overlaped or not        
	int64_t area1 = (C - A) * (D - B);
	int64_t area2 = (G - E) * (H - F);

	int64_t overlapped_area = overlap(A, B, C, D, E, F, G, H);
	return area1 + area2 - overlapped_area;
    }
private:
    int64_t overlap(int A, int B, int C, int D, int E, int F, int G, int H)
    {
	int64_t h1 = max(A, E);
	int64_t h2 = min(C, G);
	int64_t h = h2 - h1;
	if(h <= 0) return 0; //no overlapped 
	
	int64_t v1 = max(F, B);
	int64_t v2 = min(D, H);
	int64_t v = v2 - v1;
	if(v <= 0) return 0;

	return h*v;
    }
};
