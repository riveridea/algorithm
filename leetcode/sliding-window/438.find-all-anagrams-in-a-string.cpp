/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (38.31%)
 * Total Accepted:    152.3K
 * Total Submissions: 392.4K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //this is very similar with 76 
        //the difference is the length of window should be 
        //the same as size of p
        vector<int> res;
        if(s.size() == 0) return res;

        int start = 0, count = 0, len = INT_MAX;
        unordered_map<char, int> m;
        for(auto c : p){
            ++m[c]; 
        }


        //start sliding
        for(int i = 0; i < s.size(); i++){
            if(--m[s[i]] >= 0) count++;
            //check if a candidate window is found
            while(count == p.size()){
                len = i - start + 1;
                if(++m[s[start]] > 0) count--;
                if(len == p.size()) res.push_back(start);
                start++;
            }
        }
        return res;
    }
};
