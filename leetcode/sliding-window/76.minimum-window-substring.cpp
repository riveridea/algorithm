/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (31.82%)
 * Total Accepted:    286K
 * Total Submissions: 888.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
class Solution {
public:
    string minWindow(string s, string t) {
        //sliding window with hashmap to count the occurence of char in t
        string res = "";
        if(!s.size()) return res;
        int start = 0, count = 0, minLen = INT_MAX;
        unordered_map<char, int> m;

        for(auto c: t){
            ++m[c];
        }

        //start sliding
        for(int i = 0; i < s.size(); i++){
            //there is a trick here, for those char not in T, can only get negative
            //so no need to find firstly
            if(--m[s[i]] >= 0) ++count; //find a unique char in T
            //once we find a window containing all the chars in T, need to 
            //trim to find the actual start
            while(count == t.size()){
                if(minLen > i - start +1)
                {
                    minLen = i - start + 1;
                    res = s.substr(start, minLen);
                }
                if(++m[s[start]] > 0) count--;
                ++start;
            }
        }
        return res;
    }
};
