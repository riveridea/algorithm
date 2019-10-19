/*
 * [340] Longest Substring with At Most K Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
 *
 * algorithms
 * Hard (41.34%)
 * Total Accepted:    91.5K
 * Total Submissions: 221.3K
 * Testcase Example:  '"eceba"\n2'
 *
 * Given a string, find the length of the longest substring T that contains at
 * most k distinct characters.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: T is "ece" which its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", k = 1
 * Output: 2
 * Explanation: T is "aa" which its length is 2.
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
	//sliding window, hashmap to record the size of distinct 
	//characters in this window while updating the max longest 
	if(s.size() == 0)  return 0;
	if(!k) return 0;

	unordered_map<char, int> dmap;
	int left = 0, maxlen = 1;	
	for(int right = 0; right < s.size(); right++){
	    dmap[s[right]]++;
	    if(dmap.size() >= k + 1){
		//update the left to remove the left most 
		//to decrease one char 
		while(left <= right && dmap.size() >= k+1){
		    if(--dmap[s[left]] <= 0) dmap.erase(s[left]);
		    left++;
		}
	    }
	    maxlen = max(maxlen, right - left + 1);
	}
	return maxlen;
    }
};











