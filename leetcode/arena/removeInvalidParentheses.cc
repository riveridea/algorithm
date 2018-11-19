#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if(s==""){
            result.push_back(s);
            return result;
        } 
        /*** use the visited to record the visited string ***/
        unordered_set<string> visited;
        /*** use the deque to do the BFS ***/
        deque<string> queue;
        queue.push_back(s);
        visited.insert(s);
        bool found=false;
        while(!queue.empty()){
	    found = false;
            string temp=queue.front();
	    cout << "pop out a new temp string " << temp << endl;
            queue.pop_front();
            if(check(temp)){
                result.push_back(temp);
                found=true;
            }
            /*** if found, stop to increase the level depth ***/
	    cout << "found = " << found << endl;
            if(found)  continue;
            for(int i=0; i<temp.size(); i++){
		cout << i << endl;
                if(temp[i]!='(' && temp[i]!=')') continue;
		cout << "temp.substr(0, i):" << temp.substr(0, i) << " "; 
	        cout << "temp.substr(i+1):" << temp.substr(i+1) << endl;	
                string str=temp.substr(0, i)+temp.substr(i+1);
		cout << "next candidated string for queue " << str << endl;
                if(visited.find(str)==visited.end()){
                    queue.push_back(str);
                    visited.insert(str);
		    cout << "queue this string " << str << endl;
                }
            }
        }
        return result;
    }
    
    bool check(string s){
        int count=0;
        for(int i=0; i<s.size(); i++){
            char c=s[i];
            if(c=='(') count++;
            if(c==')') {
                if(count==0)    return false; 
                count--;
            }
        }
        return count==0;
    }
};

int main()
{
    string s = "())())()";
    Solution ss;
    vector<string> result = ss.removeInvalidParentheses(s);
    
    for(auto so : result)
    {
	cout << so << endl;
    }
}
