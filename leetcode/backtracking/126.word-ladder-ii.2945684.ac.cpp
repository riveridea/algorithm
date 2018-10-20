/*
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (15.86%)
 * Total Accepted:    96.3K
 * Total Submissions: 607.5K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        unordered_set<string> current, next; //store the current level and next level nodes
        unordered_set<string> visited; // determine if the node is visisted or not
        unordered_map<string, vector<string> > father; // the tree used to backtracking the path
        bool found = false;
        
        current.insert(start);
        while(!current.empty() && !found){
            //firstly set the current queue node as visited
            for(auto word: current){
                visited.insert(word);
            }
            for(auto word: current){
                string new_word = word;
                for(int i=0; i<word.size(); i++){
                    for(char c='a'; c <= 'z'; c++){
                        swap(new_word[i], c);
                        
                        if(new_word == end){
                            found = true;
                            // dont break here, as we need to process the father
                            // if only return level, it is ok here to break
                        }
                        
                        if(dict.count(new_word) > 0 && visited.count(new_word) == 0
                            || new_word == end){ // new_word ==end must consider
                            next.insert(new_word);
                            father[new_word].push_back(word);
                        }
                        
                        swap(new_word[i], c);
                    }
                }
            }
            
            current.clear();//for set, use clear
            swap(current, next);
        }
        vector<vector<string> > result;
        if (found == true){
            vector<string> path;
            build_path(path, start, end, father, result);
        }
        return result;
    }
private:
       //all the parms use reference
        void build_path(vector<string> &path, string &start, string &word, unordered_map<string, vector<string>> &father, vector<vector<string>> &result){
            path.push_back(word);
            if(word == start){
                result.push_back(path); //find a complete path and store it into result
                reverse(result.back().begin(), result.back().end());
            }
            else{
                for(auto f: father[word]){//traversal the fathers
                    build_path(path, start, f, father, result);
                }
            }
            path.pop_back(); //delete the visited node to construct the other branch
        }
};
