/*
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (25.56%)
 * Total Accepted:    131.3K
 * Total Submissions: 513.9K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        //dynamic programming 
        //f[i] = f[j] && (s[j+1, i] belong to dict j = 0:i-1
        //The biggest problem is:
        //index for string and f are different 
        vector<string> result;
        vector<bool> f(s.size()+1, false);
        f[0] = true;
        vector<vector<bool> > cuts(f.size()+1, vector<bool>(f.size()));
        
        //dynamic programming for work breaking
        for(int i=1; i<=s.length(); i++){
            //search backward
            for(int j=i-1; j>=0;j--){
                //notes: j when indexing string, start from where i locates
                //       j when indexing f, means the string excluidng char where i locates
                if(f[j] && dict.find(s.substr(j,i-j))!= dict.end()){
                    //get a matched solution
                    f[i] = true;
                    cuts[i][j] = true; // no break here!, need go through all the possible solutions
                }
            }
        }
        vector<string> path;
        gen_path(s, cuts, s.length(), path, result);
        return result;
    }
    
    void gen_path(string s, vector<vector<bool> > cuts, int cur, vector<string> &path, vector<string> &result){
        if(cur == 0){
            string tmp;
            for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
                tmp += *iter + " ";
            tmp.erase(tmp.end() - 1);
            result.push_back(tmp);
        }
        for (int i = 0; i < s.size(); i++){
            if (cuts[cur][i]){
                path.push_back(s.substr(i, cur - i));
                gen_path(s, cuts, i, path, result);
                path.pop_back();
            }
        }
    }
};
