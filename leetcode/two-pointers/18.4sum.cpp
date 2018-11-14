/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (28.67%)
 * Total Accepted:    189.4K
 * Total Submissions: 660.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
	//like 3sum, firstly sort
	//based on the ascending property 
	//the 1st and 2nd pointer are in loop
	//the 3rd and 4th pointer approaches to each other
	//the hardest things are those boundary conditions:
	//1. handle duplicates
	//2. cut those loop explicilty unnecessary

	vector<vector<int>> result; 
	int n = nums.size();
	if(n < 4) return result;
	
	//sort!!!!!!
	sort(nums.begin(), nums.end());

	//start scrambling
	for(int i = 0; i < n - 3; i++)
	{
	    //handle duplicate
	    if(i > 0 && nums[i] == nums[i-1]) continue;
	    //cut the index which is apprently not candidate
	    if(nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
	    //may forget this impossible case, if alreayd greater than target, can stop
	    if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
	    for(int j = i+1; j < n - 2; j++)
	    {
		//handle duplicate
		if(j > i+1 && nums[j] == nums[j-1]) continue;
		//cut the index which is apparently not candidate
		if(nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
		//may forget, if already greater than target here, no more answers
		if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
		//start approaching to each other
		int left = j+1;
		int right = n-1;
		while(left < right)
		{
		    int sum = nums[i] + nums[j] + nums[left] + nums[right];
		    if(sum < target)	    
		    {
			left++;
		    }
		    else if(sum > target)
		    {
			right--;
		    }
		    else
		    {
			//got an answer
			result.push_back({nums[i], nums[j], nums[left], nums[right]});
			//handle duplicates
			do{left++;}while(left < right && nums[left] == nums[left -1]);
			do{right--;}while(left < right && nums[right] == nums[right +1]);
		    }
		}
	    }
	}

	return result;
    }
};
