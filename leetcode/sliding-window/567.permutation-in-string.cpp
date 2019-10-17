/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (39.15%)
 * Total Accepted:    61.9K
 * Total Submissions: 157.3K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //almost the same with other sliding window
        if(s2.size() == 0) return false;

        unordered_map<char, int> m;
        for(auto c: s1){
            ++m[c];
        }

        int count = 0, left = 0;
        for(int i = 0; i < s2.size(); i++){
            if(--m[s2[i]] >= 0)  count++;
            //find a candidate window containing all the char of s1
            while(count == s1.size()){
                if(s1.size() == i - left + 1) return true;
                if(++m[s2[left]] > 0) count--; 
                ++left;
            }
        }
        return false;
    }
};
