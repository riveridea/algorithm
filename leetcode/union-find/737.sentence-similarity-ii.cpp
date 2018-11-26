/*
 * @lc app=leetcode id=737 lang=cpp
 *
 * [737] Sentence Similarity II
 *
 * https://leetcode.com/problems/sentence-similarity-ii/description/
 *
 * algorithms
 * Medium (41.28%)
 * Total Accepted:    17.6K
 * Total Submissions: 42.6K
 * Testcase Example:  '["great","acting","skills"]\n["fine","drama","talent"]\n[["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]'
 *
 * Given two sentences words1, words2 (each represented as an array of
 * strings), and a list of similar word pairs pairs, determine if two sentences
 * are similar.
 * 
 * For example, words1 = ["great", "acting", "skills"] and words2 = ["fine",
 * "drama", "talent"] are similar, if the similar word pairs are pairs =
 * [["great", "good"], ["fine", "good"], 
 * ⁠["acting","drama"], ["skills","talent"]].
 * 
 * Note that the similarity relation is transitive. For example, if "great" and
 * "good" are similar, and "fine" and "good" are similar, then "great" and
 * "fine" are similar.
 * 
 * Similarity is also symmetric.  For example, "great" and "fine" being similar
 * is the same as "fine" and "great" being similar.
 * 
 * Also, a word is always similar with itself.  For example, the sentences
 * words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though
 * there are no specified similar word pairs.
 * 
 * Finally, sentences can only be similar if they have the same number of
 * words.  So a sentence like words1 = ["great"] can never be similar to words2
 * = ["doubleplus","good"].
 * 
 * 
 * Note:
 * The length of words1 and words2 will not exceed 1000.
 * The length of pairs will not exceed 2000.
 * The length of each pairs[i] will be 2.
 * The length of each words[i] and pairs[i][j] will be in the range [1, 20].
 * 
 */
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
       //union and fin
       //firstly union to group all the similar words, then check if the correspoding words are similary
       //here we expand the union in the main function but implement find separately
       if(words1.size() != words2.size()) return false;
       //union all the pairs
       for(auto edge : pairs) 
       {
	    string xs = find(edge.first); 
	    string ys = find(edge.second);
	    if(xs != ys) parents[xs] = ys;
       }

       //check if non-similary is found
       for(int i = 0; i < words1.size(); i++)
       {
	    if(words1[i] != words2[i] && find(words1[i]) != find(words2[i])) return false;
       }

       return true;
    }
private:
       unordered_map<string, string> parents;
       string find(string s)
       {
	    if(parents.count(s) == 0)
	    {
		return parents[s] = s;
	    }
	    else if(parents[s] == s)
		return s;
	    else
		return find(parents[s]);
       }

};
