/*
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (27.32%)
 * Total Accepted:    90.6K
 * Total Submissions: 331.7K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * 
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 */

/**
 * Need to implement a Trie firstly
 */
class TrieNode{
public:
    bool isKey; 
    TrieNode* children[26];
    TrieNode(): isKey(false) {
	memset(children,  NULL, sizeof(TrieNode*) * 26);
    }
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
	root = new TrieNode();		 
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
	//add the character of the word on each Trie Node
	TrieNode *itr = root;
	for(auto c : word)
	{
	    if(itr->children[c - 'a'] == NULL)
	    {
		//fill the char to this node
		itr->children[c - 'a'] = new TrieNode();
	    }
	    // go to next level no matter the current exists or not
	    itr = itr->children[c - 'a'];
	}
	//now we reach the final node and tag it as a key
	itr->isKey = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
	//using the recursion
	return query(word.c_str(), root);
    }

private:
    TrieNode* root;
   
    bool query(const char* word, TrieNode *node)
    {
	TrieNode *itr = node;
	for(int i = 0; word[i]; i++)
	{
	    //if it is a char existing 
	    if(itr && word[i] != '.')
	    {
		itr = itr->children[word[i] - 'a'];
	    }
	    else if(itr && word[i] == '.')// if it is .', then we should regard it as we have 26 tries to see if we have solution
	    {
		TrieNode *tmp = itr;
		for(int j = 0; j < 26; j++)	
		{
		    itr = tmp->children[j];  //for each alphbet, query if match in subsequent chars, should keep to iterate the son of current itr
		    //itr = itr->children[j];  //do not use this line, this will go the next level
		    if (query(word + i + 1, itr))
			return true;  //if recursion returns true, found the string
		}
	    }
	    else // this char does not show in this dictonary
		break;

	}
	return itr && itr->isKey;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
