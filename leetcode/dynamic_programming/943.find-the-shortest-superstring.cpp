/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 *
 * https://leetcode.com/problems/find-the-shortest-superstring/description/
 *
 * algorithms
 * Hard (38.46%)
 * Total Accepted:    5.1K
 * Total Submissions: 13.2K
 * Testcase Example:  '["alex","loves","leetcode"]'
 *
 * Given an array A of strings, find any smallest string that contains each
 * string in A as a substring.
 * 
 * We may assume that no string in A is substring of another string in A.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["alex","loves","leetcode"]
 * Output: "alexlovesleetcode"
 * Explanation: All permutations of "alex","loves","leetcode" would also be
 * accepted.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
 * Output: "gctaagttcatgcatc"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 12
 * 1 <= A[i].length <= 20
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
	//let us do the TSP problem with grpah + DP
	//using int i represent the set 
	
	int n = A.size();
	//dp[i][j]: in set i, the shortest length of path ending at j while every node is visisted
	//vector<vector<int>> dp;
	//dp.resize(1<<n, vector<int>(n, INT_MAX));
	int dp[1<<n][n];
	fill(&dp[0][0], &dp[0][0] + sizeof(dp)/sizeof(int), INT_MAX);
	//vector<vector<int>> path;
	int path[1<<n][n];
	//path.resize(1<<n, vector<int>(n, -1));
	//graph[i][j]: node i followed by j, the shortest length 
	//vector<vector<int>> graph;
	int graph[n][n];
	//graph.resize(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++)
	{
	    for(int j = 0; j < n; j++)
	    {
		if(i != j) graph[i][j] = calc(A[i], A[j]);
		else
		    graph[i][j] = 0;
		//cout << "graph[" << i <<"][" << j << "]=" << graph[i][j] << ",";
	    }
	}
	//cout << "\n";
	//path[i][j]: last node of of j, for set i


	//now we run dp to find the shortest path and the corresponding destination 
	int min = INT_MAX;
	int last = -1;
	for(int i = 1; i < (1 << n); i++)  //try every set 
	{
	    //fill(dp[i].begin(), dp[i].end(), INT_MAX); 
	    //for each set, check each possible final desination
	    for(int j = 0; j < n; j++){
		//j is in set i?
		if((i & (1<<j)) > 0){	
		    int pre_set = i - (1 << j); 
		    if(pre_set == 0){ // itself
			dp[i][j] = A[j].size();
		    }
		    else{
			for(int k = 0; k < n; k++){
			    if((dp[pre_set][k] < INT_MAX) && (dp[pre_set][k] + graph[k][j] < dp[i][j]))
			    {
				dp[i][j] = dp[pre_set][k] + graph[k][j]; 
				path[i][j] = k;
			    }
			}
		    }
		    if((i == (1<<n) - 1) && dp[i][j] < min){
			min = dp[i][j];
			last = j;
		    }
		}
	    }
	}

	//with last and the path, we build the output string
	stack<int> p;
	int curr_set = (1 << n) - 1;
	while(curr_set > 0)
	{
	    p.push(last);
	    int temp = curr_set;
	    curr_set -= (1 << last);
	    last = path[temp][last];
	}
	string res("");
	int i = p.top();
	p.pop();
	res += A[i];
	while(!p.empty()){
	    int j = p.top();
	    p.pop();
	    res += A[j].substr(A[j].size() - graph[i][j]);
	    i = j;
	}

	return res;
    }

private:
    //calculate from string a to string b, the shortest length to be appended
    //like a: abcd, b: bcdef
    //return 2 (ef)
    int calc(string& a, string& b){
	for(int i = 1; i < a.size(); i++){
	    if(b.find(a.substr(i)) == 0) 
		return b.size() - (a.size() - i);
	}
	return b.size();
    }
};



































