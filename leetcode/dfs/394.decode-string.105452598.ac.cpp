/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (42.38%)
 * Total Accepted:    70.7K
 * Total Submissions: 166.9K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
class Solution {
public:
    string decodeString(string s) {
        //try to use stack
        //use two stacks, one for string, one for numbers
        //every time, push the number to number stack
        //every time, push the char to the string stack
        //once ] is met, pop the string stack until [ is
        // found then, go to the number stack to pop the number
        // convert the popped string to number*string then push
        // back to the string stack
        stack<string> segs;
        stack<int> nums;
        
        int num = 0;
        string res;
        for(auto c : s)
        {
            if(isdigit(c))
            {
                num = num*10 + (c - '0');
            }
            else if(c == '[')
            {
                //prepare for next segment of string surrounded by []
                segs.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(isalpha(c))
            {
                res.push_back(c);
            }
            else if(c == ']')
            {
                //convert the num[res] to new res
                //then connect with the previous string
                string temp = res;
                for( int i = 0; i < nums.top() - 1; i++)
                {
                    res += temp;
                }
                res = segs.top() + res; //wait until [ to push this new res to segs
                segs.pop(); 
                nums.pop();
            }
        }
        return res;
    }
};
