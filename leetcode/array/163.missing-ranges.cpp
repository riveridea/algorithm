/*
 * @lc app=leetcode id=163 lang=cpp
 *
 * [163] Missing Ranges
 *
 * https://leetcode.com/problems/missing-ranges/description/
 *
 * algorithms
 * Medium (22.77%)
 * Total Accepted:    47.6K
 * Total Submissions: 209.1K
 * Testcase Example:  '[0,1,3,50,75]\n0\n99'
 *
 * Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges.
 * 
 * Example:
 * 
 * 
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 * 
 * 
 */
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
	//this is an array problem, just note all the corner cases
	//iterate the nums[i], each time record the previous one and current one,
	//the normal case is to out the [pre+1, cur-1], but there are other corner cases:
	//1. pre = cur - 1, skip the cur 
	//2. i reach nums.size(), then cur = upper + 1 
	//The importmant thing: int shuld be cast to long int for every arithmetic!!!!
	vector<string> result;
	long int pre = (long int)lower-1; //we actually print pre+1
	if(nums.empty()) 
	{
	    result.push_back(get_range(lower, upper));
	    return result;
	}
	for(int i = 0; i <= nums.size(); i++)
	{
	    long int cur = (long int)(i==nums.size() ? (long int)upper+1 : nums[i]); 
	    //cout << "[" << pre << "->" << cur << "]: " << cur - pre << endl;
	    if(cur - pre >= 2)
	    {
		result.push_back(get_range(pre+1, cur-1));	
	    }
	    pre = cur;
	}
	return result;
    }
private:
    string get_range(int x, int y)
    {
	string s = "";
	if(y == x)
	    s = to_string(x);
	else
	    s = to_string(x) + "->" + to_string(y);
	return s;
    }
};
