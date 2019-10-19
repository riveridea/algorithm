/*
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (39.66%)
 * Total Accepted:    192.5K
 * Total Submissions: 485.4K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	//using the deque, would make this problme easy one
	//each time we put a new i into the deque, all the
	//index whose value is less than nums[i] should be 
	//popped out from this deque
	//meanwhile, if the i-k whos value is in front of
	//this deque, i-k should also be removed, otherwise,
	//don't care about it
	deque<int> dq;
	vector<int> ans;

	for(int i = 0; i < nums.size(); i++){
	    if(!dq.empty() && dq.front() == i-k) dq.pop_front();
	    while(!dq.empty() && nums[dq.back()] < nums[i]){
		dq.pop_back();
	    }
	    dq.push_back(i);
	    if(i >= k-1) ans.push_back(nums[dq.front()]);
	}
	return ans;
    }
};
