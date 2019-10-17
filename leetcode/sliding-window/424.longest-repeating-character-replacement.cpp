/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (44.74%)
 * Total Accepted:    38K
 * Total Submissions: 84.9K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 * 
 * In one operation, you can choose any character of the string and change it
 * to any other uppercase English character.
 * 
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 104.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        //sliding window,
        //note! the hashmap store the occurence
        //of each possible char within that window
        //we just use the max count of that char 
        //in that window to see how many holes
        //can be filled with this char
        //if the holes is larger that k, we know
        //it cannot be continious, so try the next window
        //by start++ which means the s[start] would be 
        //decreased in the new window
        if(!s.size()) return 0;
        unordered_map<char, int> m;

        int maxCount = 0, maxLen = 0, start = 0;
        for(int end = 0; end < s.size(); end++){
            maxCount = max(maxCount, ++m[s[end]]);
            //check how many holes in the current window
            //until we got a cadidate window meeting the requirement
            while(end - start + 1 - maxCount > k){
                --m[s[start]];
                ++start;
            }
            maxLen = max(maxLen, end - start + 1); //see if the window is max
        }
        return maxLen;
    }
};
