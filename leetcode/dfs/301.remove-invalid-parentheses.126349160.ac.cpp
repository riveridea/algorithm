/*
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (36.84%)
 * Total Accepted:    88.7K
 * Total Submissions: 240.9K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 * 
 * Example 1:
 * 
 * 
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ")("
 * Output: [""]
 * 
 */
/*
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses
 *
 * algorithms
 * Hard (35.40%)
 * Total Accepted:    53.5K
 * Total Submissions: 151.2K
 * Testcase Example:  '"()())()"'
 *
 * 
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 * 
 * Note: The input string may contain letters other than the parentheses ( and
 * ). 
 * 
 * 
 * 
 * Examples:
 * 
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 * 
 * 
 * 
 * Credits:Special thanks to @hpplayer for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    bool isParenthesis(char c)
    {
	return (c == '(' || c == ')');
    }

    bool isValidString(string str)
    {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
	    if(str[i] == '(')
		cnt++;
	    else if(str[i] == ')')
		cnt--;

	    if(cnt < 0)
		return false;
	}

	return (cnt == 0);
    }

    vector<string> removeInvalidParentheses(string s) {
	//use BFS to iterate every possible next string(after possible removal)        
	//it is like greedy
        //every state is representing a candidated string!!!	
	vector<string> result;	
	if (s.empty()) 
	{
	    result.push_back("");
	    return result;
	}
	
	// visit set to ignore the already visisted string
	unordered_set<string> visit;

	//Queue to maintain BFS
	queue<string> q;
	string temp;
	bool found = false; //indidate if a solution is found, actually reach on end of path

	//push the given string as the starting node
	q.push(s);
	visit.insert(s);
	//BFS loop
	string str;
	while(!q.empty())
	{
	    str = q.front(); q.pop();
	    //check if found
	    if (isValidString(str))
	    {
		result.push_back(str);
		//cout << str << endl;
	        found = true;	
	    }

	    if(found)//we have got the minimum answer
		continue;
	    
	    for(int j = 0; j < str.length(); j++)
	    {
		if(!isParenthesis(str[j]))
		    continue;

		//Removing every possible parenthesis from str
		//and push to queue, if not visisted
		temp = str.substr(0, j) + str.substr(j + 1);
		if(visit.find(temp) == visit.end())
		{
		    q.push(temp);
		    visit.insert(temp);
		}
	    }
	}

	return result;
    }
};

