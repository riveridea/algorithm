/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path
 *
 * algorithms
 * Medium (25.78%)
 * Total Accepted:    100.2K
 * Total Submissions: 388.6K
 * Testcase Example:  '"/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 * 
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * 
 * 
 * click to show corner cases.
 * 
 * Corner Cases:
 * 
 * 
 * 
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 * 
 * 
 */
class Solution {
public:
    string simplifyPath(string path) {
	//use getline to iterate every string before a next /
	//for consecutive / like ///, becasue getline gives you "", just continue
	//use a vector to store the string between /, for .., pop back the 
	//last string 
	string res; // final result string
	string tmp; // store each extracted string between /
	vector<string> stk;
	stringstream ss(path); //as input of getline
	while(getline(ss, tmp, '/'))
	{
	    if(tmp == "" || tmp == ".") continue;
	    if(tmp == ".." && !stk.empty()) stk.pop_back(); //remove the redundant
	    else if(tmp != "..") stk.push_back(tmp);
	}

	//construct the result
	for(auto s : stk)
	{
	    res += "/" + s;
	}

	return res.empty() ? "/" : res;

    }
};
