/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (28.72%)
 * Total Accepted:    186.5K
 * Total Submissions: 649.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
	//the key is to handl single row or single column specially!!
	if(matrix.empty()) return {};
	int m = matrix.size();
	int n = matrix[0].size();

	int mm = min(m, n);	    
	int layers = mm/2 + mm%2;
	
	vector<int> result;
	//cout << "layers = " << layers;
	for(int i = 0; i < layers; i++)
	{
	    //for each layer start from the [i][i]
	    int r1 = i;
	    int r2 = m - 1 - i;
	    int c1 = i;
	    int c2 = n - 1 - i;
	    int len_h = c2 - c1 + 1, len_v = r2 - r1 - 1;
	    if(len_v < 0) len_v = 0;
	    int sublen = 0;
	    if(r2 == r1 && c1 == c2) sublen = 1;
	    else if(r1 == r2) sublen = c2 -c1 + 1;
	    else if(c1 == c2) sublen = r2 -r1 + 1;
	    else
		sublen = (r2 - r1 + 1)*2 + (c2 - c1 +1)*2 - 4;
	    vector<int> subres(sublen, 0);
	    //cout << r1 << r2 << c1 << c2 << len_h << len_v << sublen << endl;
	    //assgin the value to subres
	    int k;
	    for(k = 0; k < len_h; k++)
	    {
		subres[k] = matrix[r1][c1+k]; 
		if(r2 - r1 > 0)
		    subres[k + len_h + len_v] = matrix[r2][c2-k]; 
	    }
	    int l;
	    if(len_v > 0)
		for(l = 0; l < len_v; l++)
		{
		    subres[l + len_h] = matrix[r1+1+l][c2]; 
		    if(c2 - c1 > 0)
			subres[l + 2*len_h + len_v] = matrix[r2-1-l][c1]; 
		}
	    //cout << "[";
	    for(int x : subres)
	    {
	        //cout << x << ",";	
	        result.push_back(x);
	    }
	    //cout << "]";
	    //
	    //cout << "{";
	    //for(auto x : result)
	    //{
	    //    cout << x << ",";	
	    //}
	    //cout << "}";
	}
	//cout << "to output";
	return result;
    }
};






















