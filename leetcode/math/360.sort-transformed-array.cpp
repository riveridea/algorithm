/*
 * @lc app=leetcode id=360 lang=cpp
 *
 * [360] Sort Transformed Array
 *
 * https://leetcode.com/problems/sort-transformed-array/description/
 *
 * algorithms
 * Medium (46.10%)
 * Total Accepted:    23.6K
 * Total Submissions: 51.3K
 * Testcase Example:  '[-4,-2,2,4]\n1\n3\n5'
 *
 * Given a sorted array of integers nums and integer values a, b and c. Apply a
 * quadratic function of the form f(x) = ax2 + bx + c to each element x in the
 * array.
 * 
 * The returned array must be in sorted order.
 * 
 * Expected time complexity: O(n)
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
 * Output: [3,9,15,33]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
 * Output: [-23,-5,1,7]
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
	//this is a math problem related to quatratic function
	//it is noted that if the a is positive, then the results at two ends
	//will be greater than the middle, and if a is negative, then the results
	//at the two ends will be less than the middle
	//fill the result from the head or rear according to a value
	vector<int> result(nums.size(), 0);

	int i = 0, j = nums.size()-1;
	if(a > 0)
	{
	    int k = nums.size() - 1;
	    while(i <= j) 
	    {
		int ci = transform(a,b,c,nums[i]);
		int cj = transform(a,b,c,nums[j]);
		if(ci > cj)
		{
		    result[k--] = ci;
		    i++;
		}
		else 
		{
		    result[k--] = cj;
		    j--;
		}
	    }
	}
	else if (a < 0)
	{
	    int k = 0;
	    while(i <= j) 
	    {
		int ci = transform(a,b,c,nums[i]);
		int cj = transform(a,b,c,nums[j]);
		if(ci < cj)
		{
		    result[k++] = ci;
		    i++;
		}
		else 
		{
		    result[k++] = cj;
		    j--;
		}
	    }
	}
	else
	{
	    if(b > 0)
	    {
		for(int i = 0; i < nums.size(); i++)
		{
		    result[i] = transform(a, b, c, nums[i]);
		}
	    }
	    else if(b < 0)
	    {
		for(int i = nums.size()-1; i >= 0; i--)
		{
		    result[i] = transform(a, b, c, nums[nums.size()-i-1]);
		}
	    }
	    else
	    {
		for(int i = 0; i < nums.size(); i++)
		{
		    result[i] = c;
		}
	    }
	}
	return result;
    }

private:
    int transform(int a, int b, int c, int n)
    {
	return a*n*n + b*n + c;
    }
};
