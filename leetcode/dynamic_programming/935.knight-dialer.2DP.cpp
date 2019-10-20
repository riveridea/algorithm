/*
 * [972] Knight Dialer
 *
 * https://leetcode.com/problems/knight-dialer/description/
 *
 * algorithms
 * Medium (42.43%)
 * Total Accepted:    19.4K
 * Total Submissions: 45.8K
 * Testcase Example:  '1'
 *
 * A chess knight can move as indicated in the chess diagram below:
 * 
 * .           
 * 
 * 
 * 
 * This time, we place our chess knight on any numbered key of a phone pad
 * (indicated above), and the knight makes N-1 hops.  Each hop must be from one
 * key to another numbered key.
 * 
 * Each time it lands on a key (including the initial placement of the knight),
 * it presses the number of that key, pressing N digits total.
 * 
 * How many distinct numbers can you dial in this manner?
 * 
 * Since the answer may be large, output the answer modulo 10^9 + 7.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: 10
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: 20
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: 46
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 5000
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int knightDialer(int N) {
	//why this problem is tagged as medium?
	//I just skip the recursive with memo
	//as T(p, N) = sum(T(k, N-1)) wiht k in neighbors(p)
	//dynamic programming is considered
	//define dp[i][j] is the start from i with j hops that 
	//we get the number of numbers

	int MOD = 1000000007;
	//lets us start from 2D dynamic programming 

	vector<vector<int>> nexts = {
            {4,6},{6,8},{7,9},{4,8},{3,9,0},
            {},{1,7,0},{2,6},{1,3},{2,4}		
	};

	vector<vector<int>> dp(10, vector<int>(N));
	for(int i = 0; i < 10; i++){
	    dp[i][0] = 1;
	}

	for(int j = 1; j < N; j++){
	    for(int i = 0; i < 10; i++){
		if(nexts[i].size() == 0) continue;
		for(int n : nexts[i]){
		    dp[i][j] += dp[n][j-1];
		    dp[i][j] %= MOD;
		}
	    }
	}

	//sum all the results
	long ans = 0;
	for(int i = 0; i < 10; i++){
	    ans += dp[i][N-1];
	}
	return (int)(ans%MOD);
    }
};
