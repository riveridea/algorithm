/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (48.86%)
 * Total Accepted:    62.1K
 * Total Submissions: 127.1K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 * 
 * 
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 * 
 * 
 */
class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
       this->nums = nums; 
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
	return nums; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //the basic idea is randomly select number each time and put to the 
        //result, while removing this number from original array.
        //The trick to save time is to swap out the selected number to the 
        //position which is equal to the current iteration. 
        vector<int> result(nums);
	int len = result.size();
        for(int i = 0; i < len; i++)
        {
	    int pos = rand()%(len - i) + i;
	    swap(result[pos], result[i]);
        }
	return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

















