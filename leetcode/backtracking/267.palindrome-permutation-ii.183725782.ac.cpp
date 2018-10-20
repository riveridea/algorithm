/*
 * [267] Palindrome Permutation II
 *
 * https://leetcode.com/problems/palindrome-permutation-ii/description/
 *
 * algorithms
 * Medium (32.49%)
 * Total Accepted:    21.2K
 * Total Submissions: 65.3K
 * Testcase Example:  '"aabb"'
 *
 * Given a string s, return all the palindromic permutations (without
 * duplicates) of it. Return an empty list if no palindromic permutation could
 * be form.
 * 
 * Example 1:
 * 
 * 
 * Input: "aabb"
 * Output: ["abba", "baab"]
 * 
 * Example 2:
 * 
 * 
 * Input: "abc"
 * Output: []
 * 
 */
/*
 * [267] Palindrome Permutation II
 *
 * https://leetcode.com/problems/palindrome-permutation-ii/description/
 *
 * algorithms
 * Medium (32.49%)
 * Total Accepted:    21.2K
 * Total Submissions: 65.3K
 * Testcase Example:  '"aabb"'
 *
 * Given a string s, return all the palindromic permutations (without
 * duplicates) of it. Return an empty list if no palindromic permutation could
 * be form.
 * 
 * Example 1:
 * 
 * 
 * Input: "aabb"
 * Output: ["abba", "baab"]
 * 
 * Example 2:
 * 
 * 
 * Input: "abc"
 * Output: []
 * 
 */
class Solution {
public:
    vector<string> generatePalindromes(string s) {
	vector<string>  palindromes;
	unordered_map<char, int> counts;
	//step 1. construct a example of half parlindrom string
	for(char c : s) counts[c]++;   //count every unique char
	int odd = 0;
	char mid;
	string half;
	for(auto p : counts)
	{
	    //check the occurence of odd chars
	    if(p.second & 1) 
	    {
		odd++;
		mid = p.first; // allow 0 or 1 middle odd char 
		if(odd > 1) return palindromes; //means no possible palindromes
	    }
	    //append half of this kind of chars to the half string
	    half += string(p.second /2, p.first);
	}

	//step 2. we need all the permuations of the generated half paralindome string
	palindromes = permutations(half);

	//step 3. now construct the answer based on this half string
	for(auto &p : palindromes)
	{
	    string t(p);
	    reverse(t.begin(), t.end());
	    if(odd) t = mid + t;  //make the odd in middle
	    p += t;
	}

        return palindromes;	
    }
private: 
    //return a vector of strings including all purmuations
    vector<string> permutations(string &s)
    {
	vector<string> perms;
	string t(s); // the start string
	do{
	    perms.push_back(s);
	    next_permutation(s.begin(), s.end());
	}while(t != s);
	
	return perms;
    }
};

