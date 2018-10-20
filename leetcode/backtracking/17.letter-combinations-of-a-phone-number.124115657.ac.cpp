/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (38.46%)
 * Total Accepted:    291.1K
 * Total Submissions: 756.9K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
    vector<string> phone = {"abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
    int num_res = 0;
public:
    vector<string> letterCombinations(string digits)
    {
	    vector<string> res;

	    //init
	    int ds = digits.size();
        if(ds == 0) return res;
        
	    int dv[ds], count[ds];
	    char up[ds];
	    for(int i = 0; i < ds; i++)
	    {
	        dv[i] = digits[i] - '2'; //number at each level
	        //cout << dv[i];
	        count[i] = phone[dv[i]].size(); //length at leave level
	    }

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
	        //cout << t << " ";
	        s.pop();
	        count[level]--; //remove a letter for this current level;
	    
	        //cout << "count[" << level << "]=" << count[level] << endl;
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
		            //show_up(up, ds);
		            res.push_back(char_array_to_str(up, ds));
		            while(count[next_level] == 0)
		            {
		                next_level--;
                        if(next_level < 0) break; 
		            }
		        }

		        //cout << "next_level:  " << next_level << endl;
	        }

	        if(count[level] > 0)
	        {
		        if(level == ds - 1)
		        {
		            //reaching the last level
                    //cout << "|" << endl;
		            next_level = level;
		            add = 0;
		            //show_up(up, ds);
		            res.push_back(char_array_to_str(up, ds));
		        }
		        else
		        {
		            add = 1; 
		            next_level = level + 1;
		        }
		        //cout << "next_level:  " << next_level << endl;
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
