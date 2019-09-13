/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (51.67%)
 * Total Accepted:    60.3K
 * Total Submissions: 116.6K
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * 
 * An image is represented by a 2-D array of integers, each integer
 * representing the pixel value of the image (from 0 to 65535).
 * 
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 * 
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.  Replace the
 * color of all of the aforementioned pixels with the newColor.
 * 
 * At the end, return the modified image.
 * 
 * Example 1:
 * 
 * Input: 
 * image = [[1,1,1],[1,1,0],[1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: 
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels
 * connected 
 * by a path of the same color as the starting pixel are colored with the new
 * color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected
 * to the starting pixel.
 * 
 * 
 * 
 * Note:
 * The length of image and image[0] will be in the range [1, 50].
 * The given starting pixel will satisfy 0  and 0 .
 * The value of each color in image[i][j] and newColor will be an integer in
 * [0, 65535].
 * 
 */
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	//suppose this is just a simple DFS problem
	//iteravtive, need a stack, need a seen matrix
	stack<pair<int, int>> s;
	int m = image.size();
	int n = image[0].size();
	vector<vector<int>> seen(m, vector<int>(n, 0));
      
	pair<int, int> root(sr, sc);
	s.push(root);
	seen[sr][sc] = 1;//visited
	int oc = image[sr][sc];
	image[sr][sc] = newColor;
	int dr[] = {1, 0, -1, 0};
	int dc[] = {0, 1, 0, -1};
	while(!s.empty()){
	    pair<int,int> p = s.top(); s.pop();
	    for(int i = 0; i < 4; i++){
		int r = p.first + dr[i];
		int c = p.second + dc[i];
		if(r < 0 || c < 0 || r == m || c == n || seen[r][c] == 1 || image[r][c] != oc) 
		    continue;
		
		pair<int, int> np(r,c);
		s.push(np);
		seen[r][c] = 1;
		image[r][c] = newColor;
	    }
	}
	return image;
    }
};
