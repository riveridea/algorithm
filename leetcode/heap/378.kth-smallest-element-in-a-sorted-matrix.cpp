/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (47.43%)
 * Total Accepted:    86.8K
 * Total Submissions: 183K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
	//this problem is very similar to the k smallest pairs of sum
	int result = 0;
	if(matrix.empty()) return 0;
	int m = matrix.size(), n = matrix[0].size();
    
	auto mycmp = [&matrix](pair<int, int>& a, pair<int, int>& b){
	    return matrix[a.first][a.second] > matrix[b.first][b.second];
	};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(mycmp)> q(mycmp);

	q.emplace(0,0);
	while(k-- && q.size())
	{
	    auto idx_pair = q.top(); q.pop();
	    result = matrix[idx_pair.first][idx_pair.second];
	    //cout << result << "->";
	    if(idx_pair.first + 1 < n)
	    {
		q.emplace(idx_pair.first+1, idx_pair.second);
	    }
	    if(idx_pair.first == 0 && idx_pair.second + 1 < m)
	    {
		q.emplace(idx_pair.first, idx_pair.second+1);
	    }
	}
	return result;
    }
};





























