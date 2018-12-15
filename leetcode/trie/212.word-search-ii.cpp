/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (26.66%)
 * Total Accepted:    88.4K
 * Total Submissions: 331.6K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * Example:
 * 
 * 
 * Input: 
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * 
 * Output: ["eat","oath"]
 * 
 * 
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */
class TrieNode
{
public:
    TrieNode* next[26];
    bool isword;
    
    TrieNode(bool b = false)
    {
	for(int i = 0; i < 26; i++)
	    next[i] = nullptr;
	isword = b;
    }
};

class Trie
{
public:
    TrieNode* root;

    Trie(vector<string>& words)
    {
	root = new TrieNode();
	for(auto s: words)
	    addword(s);
    }

    void addword(string& word)
    {
	//cout << "{addword:" << word << "";
	TrieNode* p = root;
	for(auto c : word)
	{
	    //cout << "/" << c; 
	    if(p->next[c - 'a'] == nullptr) 
	    {
		cout << "new "<< c;
		p->next[c - 'a'] = new TrieNode();
	    }

	    p = p->next[c - 'a'];
	    //cout << ":" << c; 
	}
	p->isword = true;
	//cout << " done}"; 
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	//user trie to store the words and then recursively tracking evey possible path
	//of the board capture the occurence of the word
	vector<string> result; //output
	set<string> res_set; //each foudn string can only be output once
	
	if(board.empty()) return result; 
	//construct the trie
	Trie* t = new Trie(words); 
	TrieNode* root = t->root;
	cout <<"start dfs " << endl;
	for(int i = 0; i < board.size(); i++)
	{
	    for(int j = 0; j < board[0].size(); j++)
	    {
		dfs(board, i, j, res_set, "", root);
	    }
	}

	for(auto s: res_set)
	{
	    result.push_back(s);
	}
	return result;
    }
private:
    void dfs(vector<vector<char>>& board, int x, int y, set<string>& res_set, string target, TrieNode* node)
    {
	if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == ' ') return;
	
	//dfs 
	TrieNode* next = node->next[board[x][y] - 'a'];
	if(next != nullptr)
	{
	    char c = board[x][y];   	
	    target += c;
	    if(next->isword) res_set.insert(target);
	    board[x][y] = ' ';
	    
	    //dfs to the four directions
	    dfs(board, x, y+1, res_set, target, next);
	    dfs(board, x, y-1, res_set, target, next);
	    dfs(board, x+1, y, res_set, target, next);
	    dfs(board, x-1, y, res_set, target, next);

	    //recover the current point
	    board[x][y] = c;
	}
    }
};
































