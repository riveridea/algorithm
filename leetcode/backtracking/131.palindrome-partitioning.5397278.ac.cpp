/*
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (37.75%)
 * Total Accepted:    137.1K
 * Total Submissions: 363.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        //Depth First Search, Recursive Version
        vector<vector<string>> results;
        vector<string> solution;
        
        dfs_partition(s, 0, solution, results);
        return results;
    }
    
    void dfs_partition(string &s, int start, vector<string> &solution, vector<vector<string> > &results){
        //travel the end of the string
        if(start == s.size()){
            results.push_back(solution);
            return;
        }
        
        //traversal all the possible next cuts, firstly determine if the part before the cut are
        //palindrome, then DFS for the part after the cut
        for(int i=start; i< s.size(); i++){
            if (is_palindrome(s, start, i)){//the first part is palindrome, then insert to the solution
                solution.push_back(s.substr(start, i-start+1));
                //go ahead with the DFS for the part after the cut
                dfs_partition(s, i+1, solution, results);
                //all the solution already pushed into results for this cut of dfs, clear it.
                solution.pop_back();
            }
        }
    }
    
    bool is_palindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
