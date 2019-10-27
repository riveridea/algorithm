#include<string> 
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

bool myfunc(string& a, string& b){
    int la = a.size(), lb = b.size();
    for(int i = 0; i < min(la, lb); i++){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }

    return la < lb;
}

int main(){
    vector<string> dict({"fa", "abc", "abde", "acf", "cbf", "ccfe"});
    
    sort(dict.begin(), dict.end(), myfunc);

    for(auto s: dict){
        cout << s << ",";
    }

    string query = "ca";
    vector<string>::iterator lb = lower_bound(dict.begin(), dict.end(), query);
    if(lb != dict.end()) cout << "\n" << *lb << endl;
    else
        cout << "\n no suggests\n";
    cout << endl;
    return 0;
}
