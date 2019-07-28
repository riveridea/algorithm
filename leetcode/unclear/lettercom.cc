#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution{
    vector<string> phone = {"abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
    int num_res = 0;
public:
    vector<string> letterCombinations(string digits)
    {
	vector<string> res;

	//init
	int ds = digits.size();
	int dv[ds], count[ds];
	char up[ds];
	for(int i = 0; i < ds; i++)
	{
	    dv[i] = digits[i] - '2'; //number at each level
	    cout << dv[i];
	    count[i] = phone[dv[i]].size(); //length at leave level
	    cout << count[i];
	}
	cout << endl;

	stack<char> s;
	int level = 0;
	int next_level = 0;
	int swl = 0;
	for(int j = 0; j < count[level]; j++)
	{
	    s.push(phone[dv[level]][j]);
	}

	//start iterative dfs
	int add = 0;
	while(!s.empty())
	{
	    char t = s.top();
	    up[level] = t;
	    cout << t << " ";
	    s.pop();
	    count[level]--; //remove a letter for this current level;
	    
	    cout << "count[" << level << "]=" << count[level] << endl;
	    if(count[level] == 0)
	    {
		if(level < ds - 1)
		{
		    add = 1;
		    next_level = level + 1;
		}
		else
		{
		    add = 0;
		    show_up(up, ds);
		    res.push_back(char_array_to_str(up, ds));
		    while(count[next_level] == 0)
		    {
			next_level--;
		    }
		}

		cout << "next_level:  " << next_level << endl;
	    }

	    if(count[level] > 0)
	    {
		if(level == ds - 1)
		{
		    //reaching the last level
		    //cout << "|" << endl;
		    next_level = level;
		    add = 0;
		    show_up(up, ds);
		    res.push_back(char_array_to_str(up, ds));
		}
		else
		{
		    add = 1; 
		    next_level = level + 1;
		}
		cout << "next_level:  " << next_level << endl;
	    }

	    if(count[level] < 0) break;

	    if(add == 1 && next_level >= 0) 
	    {
		for(int k = 0; k < phone[dv[next_level]].size(); k++)
		{
		    s.push(phone[dv[next_level]][k]);
		}
		//recover the next level
		count[next_level] = phone[dv[next_level]].size();
	    }
	    level = next_level;
	}

	//cout << "number of result = " << num_res << endl;
	return res;
    }

    void show_up(char *up, int ds)
    {
	cout << "[";
	for(int k = 0; k < ds; k++)
	{
	    cout << up[k];
	}
	cout << "]" << endl;
	num_res++;
    }

    string char_array_to_str(char *up, int ds)
    {
	string ans = "";
	for(int i = 0; i < ds; i++)
	{
	    ans += up[i];
	}
	return ans;
    }
};

int main()
{
    Solution s;
    vector<string> result = s.letterCombinations("999999");
    for(auto ans : result)
    {
	cout << "[" << ans << "]" << endl;
    }

    return 1;
}
