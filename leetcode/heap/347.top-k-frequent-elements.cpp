/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (52.02%)
 * Total Accepted:    155.1K
 * Total Submissions: 298.2K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	//use the hash table to preprocess the numbs occuring
	//use the priority queue(heap) to return the largest K frequency
	//the tricks:
	//1. priroity queue uses the frequency as the key, the number as the value
	//2. only after insert map.size - k times, we can make sure the top of
	//the priority queue's top is the in the largest k frequences
	unordered_map<int, int> m; // <number, frequency>
	for(auto n: nums)
	{
	    m[n]++;
	}
	if(m.size() < k) return {};

	vector<int> result;
	priority_queue<pair<int, int>> q; // <frequency, number>
	for(auto mm : m)	
	{
	    pair<int, int> node(mm.second, mm.first);
	    q.push(node);
	    if(q.size() > m.size() - k)
	    {
		result.push_back(q.top().second);
		q.pop();
	    }
	}
	return result;
    }
};
