/*
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (18.97%)
 * Total Accepted:    77.8K
 * Total Submissions: 410K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an array of integers, find out whether there are two distinct indices
 * i and j in the array such that the absolute difference between nums[i] and
 * nums[j] is at most t and the absolute difference between i and j is at most
 * k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	//this problem is actaully not hard, but the idea is to apply the 
	//map properly. As internally, map is sorted by its element's key 
	//thus its lower bound of nums[i] - t can be test to exist while only
	//elements with index abs(i - j) <= k in the map
	int size = nums.size();
	if(size == 0) return false;

	map<long long, int> m;
	int i=0, j=0;
	for(i = 0; i < size; i++)	
	{
	    if(i - j > k) m.erase(nums[j++]);// index out of k distance, no test 
	    map<long long, int>::iterator a = m.lower_bound((long long)(nums[i]) - t);
	    if(a != m.end() && (abs(a->first - nums[i]) <= t))
	    {
		cout << nums[i] << " " << i << endl;
		cout << a->first << " " << a->second << endl;
		return true;
	    }
	    
	    m[nums[i]] = i;
	}
	
	return false;
    }
};
