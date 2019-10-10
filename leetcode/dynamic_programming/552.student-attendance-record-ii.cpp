/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 *
 * https://leetcode.com/problems/student-attendance-record-ii/description/
 *
 * algorithms
 * Hard (34.27%)
 * Total Accepted:    14.9K
 * Total Submissions: 43.3K
 * Testcase Example:  '1'
 *
 * Given a positive integer n, return the number of all possible attendance
 * records with length n, which will be regarded as rewardable. The answer may
 * be very large, return it after mod 109 + 7.
 * 
 * A student attendance record is a string that only contains the following
 * three characters:
 * 
 * 
 * 
 * 'A' : Absent. 
 * 'L' : Late.
 * ⁠'P' : Present. 
 * 
 * 
 * 
 * 
 * A record is regarded as rewardable if it doesn't contain more than one 'A'
 * (absent) or more than two continuous 'L' (late).
 * 
 * Example 1:
 * 
 * Input: n = 2
 * Output: 8 
 * Explanation:
 * There are 8 records with length 2 will be regarded as rewardable:
 * "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
 * Only "AA" won't be regarded as rewardable owing to more than one absent
 * times. 
 * 
 * 
 * 
 * Note:
 * The value of n won't exceed 100,000.
 * 
 * 
 * 
 * 
 */
class Solution {
    long M = 1000000007;
public:
    int checkRecord(int n) {
        vector<long> f(n<=5?6:n+1);
        //f[i] is the solution with only L and P, i is the string length
        f[0] = 1; //becuase later A can be added as a solution
        f[1] = 2;
        f[2] = 4;
        f[3] = 7;
        for(int i = 4; i<=n; i++){
            f[i] = ((2*f[i-1])%M + (M - f[i-4]))%M; //make sure 0<= f[i] <M
        }
        long long sum = f[n];
        //now consider to add A
        for(int i = 1; i<= n; i++){
            sum += (f[i-1]*f[n-i])%M;
        }
        return (int)(sum%M);
    }
};
