/*
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 *
 * https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/
 *
 * algorithms
 * Hard (44.59%)
 * Total Accepted:    29.7K
 * Total Submissions: 66.6K
 * Testcase Example:  '[1,2,1,2,6,7,5,1]\n2'
 *
 * In a given array nums of positive integers, find three non-overlapping
 * subarrays with maximum sum.
 * 
 * Each subarray will be of size k, and we want to maximize the sum of all 3*k
 * entries.
 * 
 * Return the result as a list of indices representing the starting position of
 * each interval (0-indexed). If there are multiple answers, return the
 * lexicographically smallest one.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,1,2,6,7,5,1], 2
 * Output: [0, 3, 5]
 * Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting
 * indices [0, 3, 5].
 * We could have also taken [2, 1], but an answer of [1, 3, 5] would be
 * lexicographically larger.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * nums.length will be between 1 and 20000.
 * nums[i] will be between 1 and 65535.
 * k will be between 1 and floor(nums.length / 3).
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
		//this problem is very natural in solution
		//just find i, j, k to maximize the w[i] + w[j] + w[k] 
		//where w[i] is the sum start from i to i + k-1
		//there are some tricks to achieve better complexity

		int n = nums.size();
		if(!n) return {-1,-1,-1}; 

		//step 1, compute the w[i] 
		vector<int> w(n);
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += nums[i];
			if(i >= K) sum -= nums[i-K];
			if(i >= K-1) w[i-K+1] = sum; 
		}

		//step 2, compute the vector left and right
		//left[i] represents the index in [0, i] whose
		//w[index] is the largest
		//right[i] reprensents the index in [i, n-1] whose
		//w[index] is the largest
		vector<int> left(n);
		int best = 0;
		for(int i = 0; i < n; i++){
			if(w[i] > w[best]) best = i;
			left[i] = best;
		}
		vector<int> right(n);
		best = n-1;
		for(int i = n-1; i >= 0; i--){
			if(w[i] >= w[best]) best = i;
			right[i] = best;
		}

		//step 3 search the answer for j in [K, n - 1 -K],
		//to find i in [0,K-1] and k in [n-K,n-1] which 
		//maximize the the w[i] + w[j] + w[k] 
		vector<int> ans = {-1, -1, -1}; //no answer yet
		for(int j = K; j < n-K; j++){
			int i = left[j-K], k = right[j+K];
			if(ans[0] == -1 || 
			   w[i] + w[j] + w[k] > w[ans[0]] + w[ans[1]] + w[ans[2]]){
				ans[0] = i;
				ans[1] = j;
				ans[2] = k;
			}
		}
		return ans;
    }
};
