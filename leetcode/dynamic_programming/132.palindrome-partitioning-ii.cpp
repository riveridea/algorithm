/*
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (25.90%)
 * Total Accepted:    90.6K
 * Total Submissions: 349.7K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */
class Solution {
public:
    int minCut(string s) {
	//let try dynamic programming
	const int n = s.size();
	int f[n+1]; //f[i] is defined the solution that start from position i to n-1
	//need to init this array
	for(int i = 0; i <= n; i++)
	    f[i] = n-1-i;  //the maximum solution is to cut every single numer
    
	bool p[n][n];
	fill_n(&p[0][0], n*n, false);

	//start dynamic programming from known solution, which means i start from n-1
	for(int i = n - 1; i >= 0; i--)
	{
	    //find j to form a palindrom [i, j] 
	    for(int j = i; j <= n-1; j++)
	    {
		if(s[i] == s[j] && (j - i < 2 || p[i+1][j-1]))
		{
		    p[i][j] = true;
		    f[i] = min(f[i], f[j+1] + 1);
		}
	    }
	}

	return f[0];
    }
};
