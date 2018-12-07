/*
 * @lc app=leetcode id=157 lang=cpp
 *
 * [157] Read N Characters Given Read4
 *
 * https://leetcode.com/problems/read-n-characters-given-read4/description/
 *
 * algorithms
 * Easy (27.91%)
 * Total Accepted:    62.7K
 * Total Submissions: 224.8K
 * Testcase Example:  '""\n0'
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * 
 * The return value is the actual number of characters read. For example, it
 * returns 3 if there is only 3 characters left in the file.
 * 
 * By using the read4 API, implement the function int read(char *buf, int n)
 * that reads n characters from the file.
 * 
 * Example 1:
 * 
 * 
 * Input: buf = "abc", n = 4
 * Output: "abc"
 * Explanation: The actual number of characters read is 3, which is "abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: buf = "abcde", n = 5 
 * Output: "abcde"
 * 
 * 
 * Note:
 * The read function will only be called once for each test case.
 * 
 */
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
	int res = 0, incr = 0;
	for(int i = 0; i <= n/4; i++)
	{
	    incr = read4(buf + res);
	    if(!incr) break;
	    res += incr;
	}
	return min(res, n);
    }
};





































