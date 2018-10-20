/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (29.59%)
 * Total Accepted:    117.3K
 * Total Submissions: 396.4K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        vector<string> result;
        
        dfs(s, 0, 0, ip, result);
        return result;
    }
    
    void dfs(string &s, int start, int level, string ip, vector<string> &result){
        if(level == 4 && start == s.size()){
            ip.resize(ip.size() - 1);
            result.push_back(ip);
            return;
        }
        
        //check if the solution is incorrect
        //processing current step (step start from 0)
        int rest = s.size() - start;
        if (rest > (4 - level) * 3 || rest < (4 - level)) return;
        
        int num = 0;
        for(int i = start; i < start + 3; i++){
            num = num*10 + (s[i] - '0');
            
            if(num <= 255){
                ip += s[i];
                dfs(s, i+1, level+1, ip + '.', result);
            }
            if(num == 0) break; //no 0 is as prefix, when meet 0 only single 0 is permitted
        }
    }
};
