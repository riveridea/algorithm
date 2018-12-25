/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (34.26%)
 * Total Accepted:    41.4K
 * Total Submissions: 120.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies:
 * 
 * Si % Sj = 0 or Sj % Si = 0.
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
	//1. the rule to check if the new element can be added to the existing divisable subset is
	//   the new value can devide the smallest number in the set or be divibed by the largest 
	//   number in the subset.
	//2. The target is to find the largest subset, so, DP is used. Sort the nums firstly to a array 
	//   suppose T[i] is the divisable subset ending with a[i], then we try the next 
	//   T[i+1] and check any previous subset T[j] (j in 0 ~ i) and in each previus  subset,
	//   we have largest number as a[j], thus if a[j]%a[i] == 0, then a[i] can be added to the subset T[j} +1
	//   but we need to make sure T[i] to be the largest one evey time when updated it with T[j] + 1
	//3. As this problem asks to return the solution of the largest subset, thus we need to record 
	//   the selected path, thus a parent[n] is used store the parent[i] = j, and also update the last i
	//   and largest size of the subset
	sort(nums.begin(), nums.end());

	vector<int> T(nums.size(), 0);
	vector<int> parent(nums.size(), 0);

	int mlen = 0, midx = 0;
	for(int i = 0; i < nums.size(); i++)
	{
	    for(int j = i; j >= 0; j--)
	    {
		//cout << "i:" << i << "j:" << j << "T[i]" << T[i] << "T[j]" << T[j];
		//cout << "nums[i]" << nums[i] << "nums[j]" << nums[j];
		if((nums[i]%nums[j] == 0) && (T[i] < T[j] + 1))
		{
		    T[i] = T[j] + 1;
		    parent[i] = j;
		    //cout << "parent[" << i << "]=" << j << ",T["<<i<<"]="<<T[i];

		    if(T[i] > mlen)
		    {
			mlen = T[i];
			midx = i;
		    }
		}
	    }
	}
	
	//cout << "mlen:" << mlen << "midx:" << midx;
	vector<int> result;
	for(int i = 0; i < mlen; i++)
	{
	    result.push_back(nums[midx]);
	    midx = parent[midx];
	}
	return result;
    }
};













