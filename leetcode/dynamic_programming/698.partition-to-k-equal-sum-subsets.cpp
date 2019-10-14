/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (43.80%)
 * Total Accepted:    55.8K
 * Total Submissions: 127.5K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an array of integers nums and a positive integer k, find whether it's
 * possible to divide this array into k non-empty subsets whose sums are all
 * equal.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * Output: True
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= k <= len(nums) <= 16.
 * 0 < nums[i] < 10000.
 * 
 * 
 */
class Solution {
public:
    //recurseivley search the solution
    bool search(vector<int>& gs, int r, int k, vector<int>& nums, int target){
        if(r < 0) return true;
        int v = nums[r--];
        //try each group
        for(int i = 0; i < k; i++){
            if(gs[i] + v <= target){
                gs[i] += v;
                if(search(gs, r, k, nums, target)) return true;
                gs[i] -= v;
            }
            if(gs[i] == 0) break;
        }
        //no fit group
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //exhaust search
        //sort firstly then try each group recursively 
        //some recursion stop condition, like all the numbers tried, the current group 
        //has be tried but the current sum of this group is zero, no need to try the
        //next group, 
        //if the nums is used out which means for this path of search no offending found
        //only some numbers could finally cannot put to any group, we got false
        int n = nums.size();
        if(!n) return false;

        //compute the sum
        int sum = 0;
        for(auto n : nums){
            sum += n;
        }
        if(sum%k) return false;

        //sort the nums
        sort(nums.begin(), nums.end());
        int r = n;
        int target = sum/k;
        if(nums[n-1] > target) return false;
        while(--r && nums[r] == target){
            --k;
        }
        
        //now search
        vector<int> gs(k, 0);
        return search(gs, r, k, nums, target);
    }
};
