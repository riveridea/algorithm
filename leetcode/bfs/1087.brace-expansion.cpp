class Solution {
public:
    vector<string> expand(string S) {
        //BFS, each time enque a new generated combination of the previous levels combinations 
        //and next level
        //need to firslty construct the vector of vector
        vector<vector<string>> data2;

	enum state
	{
	    NULL_STATE,
	    START_OPT,
	    END_OPT,
	    ON_OPT,
	    PURE_STR 
	};

	enum state st = NULL_STATE;
	vector<string> subs;
	string pure_string;
        for(int i = 0; i < S.size(); i++)
        {
	    cout << S[i];
            switch (S[i])
            {
                case '{':
		    if(pure_string != "" && st == PURE_STR)
		    {
			vector<string> ss;
			ss.push_back(pure_string);
			data2.push_back(ss);
		    }
		    st = START_OPT;
                    break;
                case '}':
		    if(!subs.empty() && st == ON_OPT)
		    {
			data2.push_back(subs);
		    }
		    st = END_OPT;
                    break;
                case ',':
		    st = ON_OPT;
                    break; 
                default:
		    if(i == S.size() - 1)
		    {
			if(st == END_OPT)
			{
			    string s("");
			    s += S[i];
			    pure_string = s;
			    vector<string> ss;
			    ss.push_back(pure_string);
			    data2.push_back(ss);
			}
			else if(st == PURE_STR)
			{
			    vector<string> ss;
			    pure_string += S[i];
			    ss.push_back(pure_string);
			    data2.push_back(ss);
			}
		    }
		    else if(st == START_OPT)
		    {
			subs.clear();
			string s("");
			s += S[i];
			subs.push_back(s);
			st = ON_OPT;
		    }
		    else if(st == ON_OPT)
		    {
			string s("");
			s += S[i];
			subs.push_back(s);
		    }
		    else if(st == END_OPT || st == NULL_STATE)
		    {
			string s("");
			s += S[i];
			pure_string = s;
			st = PURE_STR;
		    }
		    else if(st == PURE_STR)
		    {
			pure_string += S[i];
		    }
		    else 
		    {
			cout << "error char=" << S[i] << "state="<< st;
		    }
                    break;
            }
        }
       
	//for(auto vs: data2)
	//{
	//    cout << "{";
	//    for(auto s: vs)
	//	cout << s << ",";
	//    cout << "}";
	//}
        //now bfs
        vector<string> res;
        queue<vector<string>> q;
        vector<string> str1;
        str1.push_back("");
        q.push(str1);

        while(!q.empty())
        {
            vector<string> p = q.front();
            q.pop();
            
            if (p.size() == data2.size() + 1) 
            {
                string r("");
                for(auto s3 : p)
                {
                    r += s3;
                }
                res.push_back(r);
                continue;
            }
           
            int level = p.size();
            for(int i = 0; i < data2[level -1].size(); i++) 
            {
                vector<string> p2 = p;
                p2.push_back(data2[level-1][i]);
                q.push(p2);
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};
