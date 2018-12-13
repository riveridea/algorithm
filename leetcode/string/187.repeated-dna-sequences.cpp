/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (34.66%)
 * Total Accepted:    111.4K
 * Total Submissions: 321.5K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
	//the basic idea is pretty simple, just scan the string and find each 10-letter word to 
	//increase the count of the word int the map,
	//BUT, if key is string, memory would boom!
	//the solution is to encode 10-letter to a 32bit, each 3 bits represents a char A, C, G, T
	vector<string> result;
	unordered_map<int, int> m;
	int len = s.size();
	int key = 0;
	int i = 0;
	while(i < 9)
	{
	    key = key<< 3 | (s[i++] & 7);
	}
	while(i < len)
	{
	    key = (key << 3 & 0x3FFFFFFF) | (s[i++] & 7);
	    m[key]++;
	    if(m[key] == 2)
	    {
		result.push_back(s.substr(i - 10, 10)); //becuase i already increased in previously
	    }
	}

	return result;
    }
};

























