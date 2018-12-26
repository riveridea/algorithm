/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (32.43%)
 * Total Accepted:    54K
 * Total Submissions: 166.4K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]] 
 * Explanation: The first 3 pairs are returned from the sequence: 
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [1,1],[1,1]
 * Explanation: The first 2 pairs are returned from the sequence: 
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [1,3],[2,3]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 * 
 */
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	//use the priority queue
	//the trick is the transform this problem to a problem find the k smallest 
	//elements in the m sorted arrays.
	//the smallest one is the pair(0, 0), and each time, you consider to add two or one possible 
	//cnadidates to the priority queue, if the smallest one is on the same row, then keep going 
	//toward the same row, if is the smallest in the next row, then put the next one the same row
	//and the smallest one in the next row. So you will see that 
	//push (coloum+1, row) and if column == 0, push (column, row+1)
	
	//use the pair<index, index> as the element of the priority queue, instead of value
	vector<pair<int, int>> result;
	if(k == 0 || nums1.size() == 0 || nums2.size() == 0) return result;

	auto mycmp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b){
	    return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(mycmp)> q(mycmp);

	q.emplace(0, 0); //i = 0, j = 0 must the smallest
	while(k-- && q.size() > 0)
	{
	    //find the smallest in heap
	    auto idx_pair = q.top(); 
	    q.pop();
	    
	    //push the result
	    int row = idx_pair.second;
	    int column = idx_pair.first;
	    //result.push_back(make_pair(nums1[column], nums2[row]));
	    result.emplace_back(nums1[column], nums2[row]);
	    
	    //move forward according the smallest
	    if(column + 1 < nums1.size())   //move forward in the same row
	    {
		//q.push(make_pair(column+1, row));	
		q.emplace(column+1, row);	
	    }

	    if(column == 0 && row + 1 < nums2.size()) //move downside at the left most of the row 
	    {
		//q.push(make_pair(column, row+1));
		q.emplace(column, row+1);
	    }
	}
	
	return result;
    }
};
