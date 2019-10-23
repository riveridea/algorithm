/*
 * [691] Stickers to Spell Word
 *
 * https://leetcode.com/problems/stickers-to-spell-word/description/
 *
 * algorithms
 * Hard (39.99%)
 * Total Accepted:    10.8K
 * Total Submissions: 26.9K
 * Testcase Example:  '["with","example","science"]\n"thehat"'
 *
 * 
 * We are given N different types of stickers.  Each sticker has a lowercase
 * English word on it.
 * 
 * You would like to spell out the given target string by cutting individual
 * letters from your collection of stickers and rearranging them.
 * 
 * You can use each sticker more than once if you want, and you have infinite
 * quantities of each sticker.
 * 
 * What is the minimum number of stickers that you need to spell out the
 * target?  If the task is impossible, return -1.
 * 
 * 
 * Example 1:
 * Input:
 * ["with", "example", "science"], "thehat"
 * 
 * 
 * Output:
 * 3
 * 
 * 
 * Explanation:
 * We can use 2 "with" stickers, and 1 "example" sticker.
 * After cutting and rearrange the letters of those stickers, we can form the
 * target "thehat".
 * Also, this is the minimum number of stickers necessary to form the target
 * string.
 * 
 * 
 * Example 2:
 * Input:
 * ["notice", "possible"], "basicbasic"
 * 
 * 
 * Output:
 * -1
 * 
 * 
 * Explanation:
 * We can't form the target "basicbasic" from cutting letters from the given
 * stickers.
 * 
 * 
 * Note:
 * stickers has length in the range [1, 50].
 * stickers consists of lowercase English words (without apostrophes).
 * target has length in the range [1, 15], and consists of lowercase English
 * letters.
 * In all test cases, all words were chosen randomly from the 1000 most common
 * US English words, and the target was chosen as a concatenation of two random
 * words.
 * The time limit may be more challenging than usual.  It is expected that a 50
 * sticker test case can be solved within 35ms on average.
 * 
 */
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
		//think about from the very beginning we have not set any char in the target
		//and the final state is that all the chars are set
		//if at state i, we know the minimum answer is dp[i], it has a bunch of 
		//next candidated states if we use any of the sticker can check if 
		//the unset postion of the target can be filled with the char in the next sticker
		//if any char in this sticker is used, we do the relax for the next state
		int n = target.size();
		if(!n) return 0;

		vector<int> dp(1<<n, INT_MAX);
		dp[0] = 0;
		//dp for the state
		for(int state = 0; state < 1 << n; state++){
			if(dp[state] == INT_MAX) continue; //this state has not yet be met
			for(auto s : stickers){
				int now = state;
				for(auto c : s){
					for(int i = 0; i < target.size(); i++){
						if(now & 1<<i) continue;
						if(c == target[i]){
							now |= 1 << i;	
							break; //try next char
						}
					}
				}
				if(now == state) continue;
				if(dp[now] > dp[state] + 1) dp[now] = dp[state] + 1;
			}
		}
		return dp[(1<<n)-1] == INT_MAX ? -1 : dp[(1<<n)-1];
    }
};
