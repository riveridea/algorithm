class Solution {
public:
    int longestValidParentheses(string s) {
        //Use DP, the key is to define the f[i] as the distance to its match 
        //and the iteration run from size-2 to 0
        vector<int> f(s.size(), 0); 
        
        int max_len = 0;
        for(int i= s.size() - 2; i>=0; i--){
            int match = i + f[i+1] + 1; // this is just possible match
            if(s[i] == '(' && match < s.size() && s[match] == ')'){
                f[i] = f[i+1] + 2;
                //if(f[match+1] >0 && match+1 < s.size()) f[i] += f[match+1]; //if the adjacent is a valid Parenthese
                if(match+1 < s.size()) f[i] += f[match+1];
            }
            max_len = max(max_len, f[i]);
        }
        
        return max_len;
    }
};
