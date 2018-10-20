/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (21.67%)
 * Total Accepted:    144.3K
 * Total Submissions: 665.8K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 * 
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *str, *ptr;
        bool star = false;
        
        for(str = s, ptr = p; *str != '\0'; str++, ptr++){
            switch(*ptr){
                case '?':
                    break;
                case '*':
                    star = true;
                    //store the current ptr and str
                    s = str; p = ptr;
                    //skip the duplicated *
                    while(*p == '*') p++; //Note,use *p as loop varaible
                    if (*p == '\0') return true; //Note!!! end with *
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default:
                    if(*str != *ptr){
                        if(!star) return false;
                        s++;
                        ptr = p - 1;
                        str = s - 1;
                    }
            }
        }
        while(*ptr == '*') ptr++;
        return (*ptr == '\0');
    }
};
