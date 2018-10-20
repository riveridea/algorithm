/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (24.42%)
 * Total Accepted:    237.5K
 * Total Submissions: 972.5K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
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
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //first need to understand the problme
        // "x*" means we can trasform the "x*" to a string of repeating x with 0 to more times
        // so once we find a '*' in p we need to consider if there is zero nor more repeated 
        // x in the s from the postion we find x
        
        // the questionis how many x we decide to expand?
        //use recursion
        // once we find a '*' at p+1, compare *p with *s
        // we try repeat x from 0 to more by compare 
        // if the maximum soltion tried,  try to compare the rest of s and p+2
        
        if (*p == '\0') return (*s == '\0');
        //recursion, no using while
        if(*(p+1) != '*'){ //not '*' just continue the recusion
            if(*p == *s || *p == '.' && *s != '\0'){
                return isMatch(s+1, p+1);
            }
            else
                return false; //DONT forget!!!
        }
        else{ //find '*'
            // brute trying every possible repeating solutino
            while(*p == *s || *p == '.' && *s != '\0'){
                if (isMatch(s, p+2)) return true; // got the final solution
                s++; //try next solution
            }
            //the best repeat done, compare the rest 
            return isMatch(s, p+2);
        }
    }
};
