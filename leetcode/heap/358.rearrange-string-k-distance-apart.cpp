/*
 * [358] Rearrange String k Distance Apart
 *
 * https://leetcode.com/problems/rearrange-string-k-distance-apart/description/
 *
 * algorithms
 * Hard (33.83%)
 * Total Accepted:    27K
 * Total Submissions: 79.8K
 * Testcase Example:  '"aabbcc"\n3'
 *
 * Given a non-empty string s and an integer k, rearrange the string such that
 * the same characters are at least distance k from each other.
 * 
 * All input strings are given in lowercase letters. If it is not possible to
 * rearrange the string, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: s = "aabbcc", k = 3
 * Output: "abcabc" 
 * Explanation: The same letters are at least distance 3 from each other.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaabc", k = 3
 * Output: "" 
 * Explanation: It is not possible to rearrange the string.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "aaadbbcc", k = 2
 * Output: "abacabcd"
 * Explanation: The same letters are at least distance 2 from each other.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string rearrangeString(string s, int k) {
		//this is actually a greedy problem
		//think about if the disctinct chars in the string
		//is less than k, there would be no way
		//to get the arrangement
		//meanwhile, try to put k disctinct chars 
		//each time until you cannot meet the requirement
		//or you can finished the arrangement
		string res;
		int len = s.length();
		if(!len)  return "";
		if(k == 0) return s;

		unordered_map<char, int> dict;
		priority_queue<pair<int, char>> pq;
		for(auto e: s){
			dict[e]++;
		}
		for(auto d : dict){
			pq.push(make_pair(d.second, d.first));
		}

		//try to do arrangement ,every round put k distinct char or len(len <k) 
		//if less than k remains
		//everytime arrange the most frquenent char (past ones already popped out)
		while(!pq.empty()){
			//here is a trick, we need to store those popped out pairs
			//for next round of arrangement
			vector<pair<int, char>> pops; // must use this, cannot use pq inplace
			int count = min(k, len); 
			for(int i = 0; i < count; i++){
				if(pq.empty()) return ""; //no more disctict chars but we still have positions
				pair<int, char> tmp = pq.top(); pq.pop();
				res += tmp.second;
				if(--tmp.first) pops.push_back(tmp);
				len--;
			}
			//put back the pops
			for(auto p: pops){
				pq.push(p);	
			}
		}
		return res;
    }
};
