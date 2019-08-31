/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 *
 * https://leetcode.com/problems/fruit-into-baskets/description/
 *
 * algorithms
 * Medium (41.79%)
 * Total Accepted:    62.4K
 * Total Submissions: 149.3K
 * Testcase Example:  '[1,2,1]'
 *
 * In a row of trees, the i-th tree produces fruit with type tree[i].
 * 
 * You start at any tree of your choice, then repeatedly perform the following
 * steps:
 * 
 * 
 * Add one piece of fruit from this tree to your baskets.  If you cannot,
 * stop.
 * Move to the next tree to the right of the current tree.  If there is no tree
 * to the right, stop.
 * 
 * 
 * Note that you do not have any choice after the initial choice of starting
 * tree: you must perform step 1, then step 2, then back to step 1, then step
 * 2, and so on until you stop.
 * 
 * You have two baskets, and each basket can carry any quantity of fruit, but
 * you want each basket to only carry one type of fruit each.
 * 
 * What is the total amount of fruit you can collect with this procedure?
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,1]
 * Output: 3
 * Explanation: We can collect [1,2,1].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,2,2]
 * Output: 3
 * Explanation: We can collect [1,2,2].
 * If we started at the first tree, we would only collect [0, 1].
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,2,2]
 * Output: 4
 * Explanation: We can collect [2,3,2,2].
 * If we started at the first tree, we would only collect [1, 2].
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [3,3,3,1,2,1,1,2,3,3,4]
 * Output: 5
 * Explanation: We can collect [1,2,1,1,2].
 * If we started at the first tree or the eighth tree, we would only collect 4
 * fruits.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= tree.length <= 40000
 * 0 <= tree[i] < tree.length
 * 
 * 
 */
class Solution {
public:
    int totalFruit(vector<int>& tree) {
	//this problem is the same as 159 longest substring with at most two type characters
	//Please note, each tree represents one type, so each tree can only get 1 piece of fruit
	//i - start, j - end
	//for each start, we try increamenting j until number of distinct exceed 2, then find a 
	//new start to get the number fo distincts back to 2, for each (i, j) with at most 2 distincts,
	//update the max len
	unordered_map<int, int> hmap;

	int i = 0; 
	int numDistinct = 0;
	int max_len = 0;
	
	//start slide window
	for(int j = 0; j < tree.size(); j++)
	{
	    //firstly check if this is a new type
	    if(hmap[tree[j]] == 0) numDistinct++;
	    hmap[tree[j]]++;

	    //check if numDistict exceed 2, if yes, find a new start
	    while(numDistinct > 2)
	    {
		hmap[tree[i]]--;
		if(hmap[tree[i]] == 0) numDistinct--; //cleared 1 type
		i++;
	    }
	    max_len = max(max_len, j - i +1);
	}
	return max_len;
    }
};
