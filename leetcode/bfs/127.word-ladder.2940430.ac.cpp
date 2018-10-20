/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (21.37%)
 * Total Accepted:    197.1K
 * Total Submissions: 922.1K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
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
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
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
 * Output: 0
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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.size() != end.size()) return 0;
        if (start.empty()|| end.empty()) return 0;
        
        queue<string> next, current; //used to store the current and next level nodes
        unordered_set<string> visited; //to store the visited nodes, indexed by string value
        int level = 0;
        bool found = false;
        
        current.push(start);
        while(!current.empty() && !found){
            ++level;
            while(!current.empty() &&!found){ //travasal the current queue to get the next level as the next queue
                const string str(current.front());
                current.pop();
                
                for(int i=0; i<str.size(); i++){
                    string new_word(str);
                    for(char c='a'; c<='z'; c++){
                        swap(new_word[i], c); //check the possbile next node 
                        if(new_word == end){//found the target word
                            found = true;
                            break;
                        }
                        
                        //not 
                        if(dict.count(new_word) > 0 
                            && !visited.count(new_word)){
                                next.push(new_word);
                                visited.insert(new_word);
                            }
                        swap(new_word[i], c); //resume the original word
                    }
                }
            }
            
            swap(next, current); //before swap, current is already empty
        }
        
        if(found) return level+1;
        return 0;
    }
};
