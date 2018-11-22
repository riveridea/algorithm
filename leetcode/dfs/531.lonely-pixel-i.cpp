/*
 * [531] Lonely Pixel I
 *
 * https://leetcode.com/problems/lonely-pixel-i/description/
 *
 * algorithms
 * Medium (56.67%)
 * Total Accepted:    14.4K
 * Total Submissions: 25.5K
 * Testcase Example:  '[["W","W","B"],["W","B","W"],["B","W","W"]]'
 *
 * Given a picture consisting of black and white pixels, find the number of
 * black lonely pixels.
 * 
 * The picture is represented by a 2D char array consisting of 'B' and 'W',
 * which means black and white pixels respectively. 
 * 
 * A black lonely pixel is character 'B' that located at a specific position
 * where the same row and same column don't have any other black pixels.
 * 
 * Example:
 * 
 * Input: 
 * [['W', 'W', 'B'],
 * ⁠['W', 'B', 'W'],
 * ⁠['B', 'W', 'W']]
 * 
 * Output: 3
 * Explanation: All the three 'B's are black lonely pixels.
 * 
 * 
 * 
 * Note:
 * 
 * The range of width and height of the input 2D array is [1,500].
 * 
 * 
 */
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
	//this should be a DFS but pretty simple
	int lone = 0;
	m = picture.size();
	if (m == 0) return 0;
	n = picture[0].size(); 
	//four directions
	int d[4] =  {0, 1, 0, -1}; 
	for (int i = 0; i < m; i++)
	{
	    for (int j = 0; j < n; j++)
	    {
		if(picture[i][j] == 'B')
		{
		    if (check(i, j , picture, d))
			lone++;
		}
	    }
	}

	return lone;
    }

private:
    int m;
    int n;
    bool check(int x, int y, vector<vector<char>>& p, int* d)
    {
	if (x < 0 || y < 0 || x >= m || y >= n)
	{
	    return false;
	} 
	
	for (int i = 0; i < 4; i++)
	{
	    int nx = x;
	    int ny = y;
	    //need to go to the same direction until the wall
	    while(1){
		nx += d[i];
		ny += d[(i+1)%4];

		if(nx < 0 || ny < 0 || nx >= m || ny >= n)
		{
		    break;
		}
		if(p[nx][ny] == 'B') return false;
	    }; 

	} 
    
	return true; 
    }
};
