/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (27.94%)
 * Total Accepted:    36.5K
 * Total Submissions: 130.6K
 * Testcase Example:  '"112358"'
 *
 * Additive number is a string whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 * 
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 * 
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 * 
 * Example 1:
 * 
 * 
 * Input: "112358"
 * Output: true 
 * Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5,
 * 8. 
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "199100199"
 * Output: true 
 * Explanation: The additive sequence is: 1, 99, 100, 199. 
 * 1 + 99 = 100, 99 + 100 = 199
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 */
class Solution {
public:
    bool isAdditiveNumber(string num) {
	//backtracking(DFS) with pruneing
	//the basic idea is scan every pos from 0, and try every possile step length in [1, total_len - pos]
	//maitain a vector<int> nums to store the temparay numbers converted from the sub strings.
	//the backtracking condistion is if the nums does not validate the addtitive number, or 
	//the dfs does return false. The dfs stopping conditon is if pos hit total_len, then check nums valid
	//or not.
	vector<long long> nums;
	long_max = to_string(LLONG_MAX);
	return dfs(nums, num, 0, num.size());
    }
private:
    string long_max;

    bool is_valid(vector<long long> nums)
    {
	if (nums.size() < 3) return false;
	//for(int i = 2; i < nums.size(); i++)
	//{
	//    if(nums[i] != nums[i-1] + nums[i-2])  return false;
	//}
	int n = nums.size();
	if(nums[n - 1] != nums[n - 2] + nums[n - 3]) return false;
	return true;
    }
    bool dfs(vector<long long>& nums, string& str, int pos, int N)
    {
	if(pos == N)
	{
	    return is_valid(nums);
	}


	for(int i = 1; i <= N - pos; i++)   //Note, i is the length, including N - pos
	{
	    //prune when '0'
	    if(str[pos] == '0' && i > 1) break;   //Note, check pos == 0, not i

	    string sub = str.substr(pos, i); //TRY this substring
	    //prune when sub is max value that subsequent value cnannot be greater
	    if(sub.size() > long_max.size() || (sub.size() == long_max.size() && sub.compare(long_max) > 0)) break;
	    nums.push_back(stoll(sub)); // push this number and will dfs
	    
	    //prune when current nums does not fit or its next dfs cannot fit, backtracking by remove this number
	    if((nums.size() > 2 && !is_valid(nums)) || !dfs(nums, str, pos+i, N))  nums.pop_back();
	    else
		return true;
	}

	return false;
    }
};


















