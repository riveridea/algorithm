/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 *
 * https://leetcode.com/problems/range-addition/description/
 *
 * algorithms
 * Medium (59.31%)
 * Total Accepted:    22.3K
 * Total Submissions: 37.6K
 * Testcase Example:  '5\n[[1,3,2],[2,4,3],[0,2,-2]]'
 *
 * Assume you have an array of length n initialized with all 0's and are given
 * k update operations.
 * 
 * Each operation is represented as a triplet: [startIndex, endIndex, inc]
 * which increments each element of subarray A[startIndex ... endIndex]
 * (startIndex and endIndex inclusive) with inc.
 * 
 * Return the modified array after all k operations were executed.
 * 
 * Example:
 * 
 * 
 * Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
 * Output: [-2,0,3,5,3]
 * 
 * 
 * Explanation:
 * 
 * 
 * Initial state:
 * [0,0,0,0,0]
 * 
 * After applying operation [1,3,2]:
 * [0,2,2,2,0]
 * 
 * After applying operation [2,4,3]:
 * [0,2,5,5,3]
 * 
 * After applying operation [0,2,-2]:
 * [-2,0,3,5,3]
 * 
 */
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
	//the trick is to use 2 steps
	//1. update the start index element with +inc, tne the end_index +1 with -inc
	//2. scan the nums with summing the nums[i] and push every new sum to result
	//this way can save the time complexity, as the operation in the range can 
	//be memorized and pipedlined by the sum operation in the step 2,because inc is
	//fixed in each operation
	vector<int> result, array(length+1, 0); //length + 1 is used to extend to the end+1	
	//preprocessing according to updates
	for(auto op : updates)
	{
	    array[op[0]] += op[2];
	    array[op[1] + 1]  -= op[2];
	}

	//sum to get the result
	int sum = 0;
	for(int i = 0; i < length; i++)
	{
	    sum +=  array[i];
	    result.push_back(sum);
	}
	return result;
    }
};





































