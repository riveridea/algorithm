/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 *
 * https://leetcode.com/problems/longest-absolute-file-path/description/
 *
 * algorithms
 * Medium (38.32%)
 * Total Accepted:    57.4K
 * Total Submissions: 149.8K
 * Testcase Example:  '"dir\\n\\tsubdir1\\n\\tsubdir2\\n\\t\\tfile.ext"'
 *
 * Suppose we abstract our file system by a string in the following manner:
 * 
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 * 
 * dir
 * ⁠   subdir1
 * ⁠   subdir2
 * ⁠       file.ext
 * 
 * 
 * The directory dir contains an empty sub-directory subdir1 and a
 * sub-directory subdir2 containing a file file.ext.
 * 
 * The string
 * "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
 * represents:
 * 
 * dir
 * ⁠   subdir1
 * ⁠       file1.ext
 * ⁠       subsubdir1
 * ⁠   subdir2
 * ⁠       subsubdir2
 * ⁠           file2.ext
 * 
 * 
 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1
 * contains a file file1.ext and an empty second-level sub-directory
 * subsubdir1. subdir2 contains a second-level sub-directory subsubdir2
 * containing a file file2.ext.
 * 
 * We are interested in finding the longest (number of characters) absolute
 * path to a file within our file system. For example, in the second example
 * above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and
 * its length is 32 (not including the double quotes).
 * 
 * Given a string representing the file system in the above format, return the
 * length of the longest absolute path to file in the abstracted file system.
 * If there is no file in the system, return 0.
 * 
 * Note:
 * 
 * The name of a file contains at least a . and an extension.
 * The name of a directory or sub-directory will not contain a ..
 * 
 * 
 * 
 * Time complexity required: O(n) where n is the size of the input string.
 * 
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is
 * another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 */
class Solution {
public:
    int lengthLongestPath(string input) {
	//we need to keep tracking the path depth and total length until now, for reach line(ending \n)
	//a stack is used to store this infomraiton, and once the current depth is the same or less than
	//the top of the stack, you need to pop the top of the stack as the top node is not needed now
	//The depth of the line depends on the number of  \t
	stack<pair<int, int>> stk; //pair<depth, tlen>
	if(!input.size()) return 0;

	int maxLen = INT_MIN;
	int depth = 0; 
	int tlen = 0;
	int dots = 0;
	for(int i = 0; i < input.size(); i++)
	{
	    //cout << input[i] << endl;
	    if(input[i] != '\n') 
	    {
		if(input[i] == '\t') depth++;
		else if(input[i] == '.') dots++;
		else
		{
		    tlen++;
		}
		if(i < input.size() - 1)
		    continue;
	    }
	    
	    while(!stk.empty() && depth <= stk.top().first)
	    {
		stk.pop();
	    }
	    if(dots)
	    {
		if(stk.size())
		    maxLen = max(maxLen, stk.top().second + tlen + dots);
		else
		    maxLen = max(maxLen, tlen+dots);
	    }
	    else
	    {
		if(stk.size())
		    stk.push(make_pair(depth, stk.top().second + tlen + 1));	
		else
		    stk.push(make_pair(depth, tlen + 1));	
	    }
	    tlen = 0; dots = 0; depth = 0;
	}
	return maxLen == INT_MIN ? 0 : maxLen;
    }
};


















































