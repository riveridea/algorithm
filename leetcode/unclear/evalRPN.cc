#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayTokens(vector<string> &tokens){
	vector<string>::iterator it = tokens.begin();
	for( ; it != tokens.end(); ++it){
    		std::cout << ' ' << *it;
	}
	std::cout << endl;
}

class Solution{
public:
	int evalRPN(vector<string> &tokens){
		vector<string>::iterator it = tokens.begin();
		int x, y;
		if(tokens.size() == 1 && !isOperator(*it)){
			cout << ' ' << *it;
			return stoi(*it);
		}
		while(it != tokens.end()){
				//cout << ' ' << *it;
				if(isOperator(*it)){ //find the most left operator
					if(tokens.size() == 1) exit(1); //only 1 operator left
					if(tokens.size() == 2) return stoi(*(it-1));

					x = stoi(*(it-2));
					y = stoi(*(it-1));
					//cout << "x =" << x << " y=" << y <<endl;
					if(*it == "+") x += y;
					if(*it == "-") x -= y;
                                        if(*it == "*") x *= y;
					if(*it == "/") x /= y;	
								
					//remove the used node and operator
					tokens.erase(it-1);
					tokens.erase(it-1); //pay attention, the iterator is changing
					*(it-2) = to_string(x);
					displayTokens(tokens);
					break; //go out the while, and get to work in the recursive evalRPN
				}
			it++;	
		}

		return evalRPN(tokens); //recursive call	
	}
private:
	bool isOperator(string &token){
		return (token == "+" || token == "-" || token == "*" || token == "/");
	}	
};



int main(){
	vector<string> tokens;
	string token;

	do{
		cin>> token;
 		if (token!= "%"){
			tokens.push_back(token);
		}
		else break;
	}while(1);

	Solution sltn;
	displayTokens(tokens);
	cout << "end is " << *tokens.end();
        int result = sltn.evalRPN(tokens);
	return 0;
}
