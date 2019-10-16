/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (27.84%)
 * Total Accepted:    41.5K
 * Total Submissions: 148.1K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game," two players take turns adding, to a running total, any
 * integer from 1..10. The player who first causes the running total to reach
 * or exceed 100 wins. 
 * 
 * What if we change the game so that players cannot re-use integers? 
 * 
 * For example, two players might take turns drawing from a common pool of
 * numbers of 1..15 without replacement until they reach a total >= 100.
 * 
 * Given an integer maxChoosableInteger and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both players
 * play optimally. 
 * 
 * You can always assume that maxChoosableInteger will not be larger than 20
 * and desiredTotal will not be larger than 300.
 * 
 * 
 * Example
 * 
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 * 
 * Output:
 * false
 * 
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 * 
 * 
 */
class Solution {
    unordered_map<int, bool> states;
    vector<bool> used; 
public:
    int format(vector<bool>& used){
        int num = 0;
        for(int i = 1; i < used.size(); i++){
            if(used[i] == true)  num |= (1<<(i-1));
        }
        return num;
    }

    bool search(int remain){
        if(remain <= 0) return false; //win last player
        int s = format(used);
        if(states.find(s) == states.end())//have not reached this state yet
        {
            //try every possible next state
            for(int i = 1; i < used.size(); i++){
                if(used[i] == false){
                    used[i] = true;
                    if(!search(remain - i)){ //lost by next player
                        states[s] = true; //this state leading to win for current player
                        used[i] = false;
                        return true;
                    }
                    used[i] = false; //backtracking
                } 
            }
            //if reaching here, measn this state leads to lose for this player
            states[s] = false; 
        }
        return states[s];
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //such problem, actuall you need to try every state transition 
        //as a graph and use backtracking to iterate each state 
        //until you find if player one can win or not
        //STATE!!! - is defined as the remaining desireTotal marked by
        //the used array, each number is ether used or not
        //to trace the used state, we need a corresponding integer
        if(desiredTotal <= 0) return true;
        int maxc = maxChoosableInteger;
        int sum = (1+maxc)*maxc/2;
        if(sum < desiredTotal) return false; 
        
        //start recursive searching with backtracking
        used.resize(maxc+1, false);
        return search(desiredTotal);
    }
};
