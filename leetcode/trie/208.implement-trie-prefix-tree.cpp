/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (35.20%)
 * Total Accepted:    148.5K
 * Total Submissions: 421.7K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
class TrieNode {
public:
    TrieNode* next[26];
    bool isword;

    //constructor
    TrieNode(bool b = false)
    {
	memset(next, 0, sizeof(next));
	isword = b;
    }
};


class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
	root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
	TrieNode *node = root;
	if (!root || !word.size()) return;  
	for(auto s : word)
	{
	    if(node->next[s-'a'] == NULL) node->next[s-'a'] = new TrieNode();     

	    node = node->next[s-'a'];
	}
	node->isword = true; //hit a end of word	
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
	TrieNode* res = find(word);
	return res != NULL && res->isword; //don't forget to hit an end of word
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       //this is different to the search, it does only need prefix matching
       return find(prefix) != nullptr;
    }

private:
    TrieNode* find(string key)    
    {
	TrieNode* node = root;
	for(auto s : key)
	{
	    if(!node) return nullptr;
	    node = node->next[s-'a'];
	}
	return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

























