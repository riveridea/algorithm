#include <string>
#include <iostream>
#include <sstream>
#include <istream>
#include <iterator>
#include <vector>

using namespace std;

int delimit(const string& s, char d, vector<string>& result){
    if(result.size() > 0) return 0;
    stringstream  ss(s);
    while(ss.good()){
        string substr;
        getline(ss, substr, d);

        result.push_back(substr);
    }
    return result.size();
}

int main(){
    string text = "Let me split this into words";
     
    istringstream iss(text);
    vector<string> results((istream_iterator<std::string>(iss)),
                                 istream_iterator<std::string>());

    string input;
    getline(cin, input);
   
    vector<string> result;
    if(delimit(input, ',', result) > 0)
        for(auto s : result){
            vector<string> strs;
            if(delimit(s, ' ', strs) == 1)
                cout << s << endl;
            else{
                cout << "[";
                for(auto s1: strs){
                    cout << s1 << " "; 
                }
                cout << "]" << endl;
            }
        }

    return 1;
}
