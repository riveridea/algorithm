/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.25%)
 * Total Accepted:    78.2K
 * Total Submissions: 199.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an unsorted array return whether an increasing subsequence of length 3
 * exists or not in the array.
 * 
 * Formally the function should:
 * 
 * Return true if there exists i, j, k 
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return
 * false.
 * 
 * Note: Your algorithm should run in O(n) time complexity and O(1) space
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,4,3,2,1]
 * Output: false
 * 
 * 
 * 
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
	//to achieve, O(1) space and O(n) time, just use two cache m1, m2 to track
	//the first 2 increasing numbers and then see if the third one is greater than
	//m1 and m2
	//Note: Triplets are not required to contigous
	//thus we got m2 updatd thus we have a least a 2 increased numbers,  then find the third one will give
	//the true
	int m1 = INT_MAX, m2 = INT_MAX;

	for(auto c : nums)
	{
	    if(m1 >= c) m1 = c;
	    else if(m2 >= c) m2 = c;  // this c is greater than m1, but will be used as m2, we got a m1 < m2
	    else
		return true;
	}

	return false;
    }
};
