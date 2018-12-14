/*
 * @lc app=leetcode id=244 lang=cpp
 *
 * [244] Shortest Word Distance II
 *
 * https://leetcode.com/problems/shortest-word-distance-ii/description/
 *
 * algorithms
 * Medium (44.48%)
 * Total Accepted:    39.9K
 * Total Submissions: 89.6K
 * Testcase Example:  '["WordDistance","shortest","shortest"]\n[[["practice","makes","perfect","coding","makes"]],["coding","practice"],["makes","coding"]]'
 *
 * Design a class which receives a list of words in the constructor, and
 * implements a method that takes two words word1 and word2 and return the
 * shortest distance between these two words in the list. Your method will be
 * called repeatedly many times with different parameters. 
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * 
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 * 
 * 
 * 
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 * 
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are
 * both in the list.
 * 
 */
class WordDistance {
    unordered_map<string, vector<int>> dict; 
    int len;
public:
    WordDistance(vector<string> words) {
	//initiliaze the dic
	len = words.size();
	for(int i = 0; i <len; i++)
	{
	    dict[words[i]].push_back(i);
	}
    }
    
    int shortest(string word1, string word2) {
	int dist = INT_MAX; 
	int i = 0, j = 0;
	while(i < dict[word1].size() && j < dict[word2].size())
	{
	    dist = min(dist, abs(dict[word1][i] - dict[word2][j]));	
	    if(dict[word1][i] < dict[word2][j]) //increase the left words each time unlti it becomes right
		i++;
	    else
		j++;
	}
	return dist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */










