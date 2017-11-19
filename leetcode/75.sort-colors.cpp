/*
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors
 *
 * algorithms
 * Medium (38.39%)
 * Total Accepted:    190.3K
 * Total Submissions: 495.8K
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array with n objects colored red, white or blue, sort them so that
 * objects of the same color are adjacent, with the colors in the order red,
 * white and blue.
 * 
 * 
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * 
 * 
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * 
 * 
 * click to show follow up.
 * 
 * 
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with an one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution {
static inline void swap(int *a, int *b)
    {
	int tmp = *a;
	*a = *b;
	*b = tmp;
    }
public:
    void sortColors(vector<int>& nums) {
            int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
	    //the trick is when low is ++, mid is also ++
	    //but when high -- , mid is not --
	    //because low and mid start from the same side
            while(mid <= high)
            {
                if(nums[mid] == 0)
                {
		    if(nums[low] != 0)
		    {
			tmp = nums[mid];
			nums[mid] = nums[low];
			nums[low] = tmp;
		    }
			//Solution::swap(&nums[mid], &nums[low]);
                    low++;
                    mid++;
                }
                else if(nums[mid] == 1)
                {
                    mid++;
                }
                else if(nums[mid] == 2)
                {
		    if(nums[high] != 2)
		    {
			tmp = nums[mid];
			nums[mid] = nums[high];
			nums[high] = tmp;
		    }
		//	Solution::swap(&nums[mid], &nums[high]);
                    high--;  //we don't mid++ as this nums[mid] could be 2
                }
            }
    }
};
