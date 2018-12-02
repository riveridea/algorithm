/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings
 *
 * https://leetcode.com/problems/encode-and-decode-strings/description/
 *
 * algorithms
 * Medium (25.65%)
 * Total Accepted:    34.7K
 * Total Submissions: 135.5K
 * Testcase Example:  '[]'
 *
 * 
 * Design an algorithm to encode a list of strings to a string. The encoded
 * string is then sent over the network and is decoded back to the original
 * list of strings.
 * 
 * 
 * Machine 1 (sender) has the function:
 * 
 * string encode(vector<string> strs) {
 * ⁠ // ... your code
 * ⁠ return encoded_string;
 * }
 * 
 * Machine 2 (receiver) has the function:
 * 
 * vector<string> decode(string s) {
 * ⁠ //... your code
 * ⁠ return strs;
 * }
 * 
 * 
 * 
 * So Machine 1 does:
 * string encoded_string = encode(strs);
 * 
 * 
 * 
 * and Machine 2 does:
 * vector<string> strs2 = decode(encoded_string);
 * 
 * 
 * 
 * strs2 in Machine 2 should be the same as strs in Machine 1.
 * 
 * 
 * Implement the encode and decode methods.
 * 
 * 
 * Note:
 * 
 * The string may contain any possible characters out of 256 valid ascii
 * characters. Your algorithm should be generalized enough to work on any
 * possible characters.
 * Do not use class member/global/static variables to store states. Your encode
 * and decode algorithms should be stateless.
 * Do not rely on any library method such as eval or serialize methods. You
 * should implement your own encode/decode algorithm.
 * 
 */
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
	//this problem may not be related to algorithm
	string encoded = "";
	for (string str: strs)
	{
	    int len = str.size();
	    encoded += to_string(len) + "@" + str;
	}

	return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
	int head = 0; //position for each string
	while(head < s.size())
	{
	    int pos = s.find_first_of('@', head);    
	    int len = stoi(s.substr(head, pos - head)); 
	    head = pos + 1;
	    res.push_back(s.substr(head, len)); 
	    head += len;
	}
	return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
