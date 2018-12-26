/*
 * @lc app=leetcode id=245 lang=cpp
 *
 * [245] Shortest Word Distance III
 *
 * https://leetcode.com/problems/shortest-word-distance-iii/description/
 *
 * algorithms
 * Medium (52.21%)
 * Total Accepted:    33.7K
 * Total Submissions: 64.6K
 * Testcase Example:  '["practice", "makes", "perfect", "coding", "makes"]\n"makes"\n"coding"'
 *
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 * 
 * word1 and word2 may be the same and they represent two individual words in
 * the list.
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * 
 * Input: word1 = “makes”, word2 = “coding”
 * Output: 1
 * 
 * 
 * 
 * Input: word1 = "makes", word2 = "makes"
 * Output: 3
 * 
 * 
 * Note:
 * You may assume word1 and word2 are both in the list.
 * 
 */
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
	//try not using the hash table as the shortest word distance ii
	//use two pointers to track the word1 and word2 appearing position
	//and update the minimum distance 
	//the only thing to note is when word1 and word2 is the same, 
	//the way to update pos is to swap the curren i1 with the current i2 to
	//update the i2 for computing i1 - i2, because ususally i2 is updated 
	//when seeing word2
	long long dist = INT_MAX;
	long long i1 = dist, i2 = -dist; //word1 and word2 could be not in the dictionary

	bool same = word1 == word2;
	for(int i = 0; i < words.size(); i++)
	{
	    if(words[i] == word1)
	    {
		i1 = i;
		if(same)
		    swap(i1, i2);
	    }
	    else if(words[i] == word2)
	    {
		i2 = i;
	    }
	    dist = min(dist, abs(i1 - i2));
	}
	return dist;
    }
};
