/*
 * [364] Nested List Weight Sum II
 *
 * https://leetcode.com/problems/nested-list-weight-sum-ii/description/
 *
 * algorithms
 * Medium (54.87%)
 * Total Accepted:    27.8K
 * Total Submissions: 50.7K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, return the sum of all integers in the list
 * weighted by their depth.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Different from the previous question where weight is increasing from root to
 * leaf, now the weight is defined from bottom up. i.e., the leaf level
 * integers have weight 1, and the root level integers have the largest
 * weight.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [[1,1],2,[1,1]]
 * Output: 8 
 * Explanation: Four 1's at depth 1, one 2 at depth 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,[4,[6]]]
 * Output: 17 
 * Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 +
 * 4*2 + 6*1 = 17.
 * 
 * 
 * 
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
    	//The idea is to use an array to store the sum of integers for each depth
    	//and this array has dynamic size
    	vector<int> sum_level;
        for(auto ni : nestedList)     
	{
            dfs(ni, 0, sum_level);
	}

	//now we have the sum at each level, just recalculate them
	int sum = 0;
	for(int index = sum_level.size() - 1, weight = 1; index >= 0; index--, weight++)
	{
	    sum += sum_level[index]*weight;
	}

	return sum;
    }
private:
    void dfs(NestedInteger ni, int index, vector<int> &sum_level)
    {
        if(sum_level.size() < index + 1)
        {
           //need to allocate new level 
           sum_level.resize(index + 1); 
        }
        
        if(ni.isInteger())
        {
	    //add this integer to the sum of this level
	    sum_level[index] += ni.getInteger();
        }
	else // iterate to the next level
	{
	    for(auto next_i : ni.getList())
	    {
		dfs(next_i, index+1, sum_level);
	    }
	}
    }
};


















