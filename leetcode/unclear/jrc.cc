#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution{
    typedef struct Point {
        int x;
        int y;  
    } pt;
public:
    bool judgeCircle(string moves) {
        //use the coordinate to
        int len = moves.size();
        if(len == 0) return true;
        bool valid_letter = true;
        pt orig;
        orig.x = 0;
        orig.y = 0;
        
        for(int i = 0; i< len; i++)
        {
            char c = moves[i];
            switch(c)
            {
                case 'U': 
                    orig.y++;
                    break;
                case 'D':
                    orig.y--;
                    break;
                case 'L':
                    orig.x--;
                    break;
                case 'R':
                    orig.x++;
                    break;
                default:
                    valid_letter = false;
                    break;      
            }
        }
        
        return (orig.x == 0 && orig.y == 0 && valid_letter);
    }
};

int main()
{
    Solution s;
    bool result = s.judgeCircle("UD");
	
    return 1;
}
