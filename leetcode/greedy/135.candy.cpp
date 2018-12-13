/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (26.99%)
 * Total Accepted:    91.5K
 * Total Submissions: 338.9K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
	//think about up and down, and count the number up and down, but
	//make sure to handle when downCnt is greather than upCnt, which means
	//the upCnt should be updated to add the extra downCnt - upCnt + 1 for 
	//upCnt to reach downCnt + 1, why, because you need to make sure the 
	//downSide guys are not getting negative and zero candy
	int upCnt = 1;
	int downCnt = 0;
	int len = ratings.size();
	if(len == 0) return 0;
	int result = 1;

	for(int i = 1; i < len; i++)
	{
	    if(ratings[i] < ratings[i-1])
	    {
		downCnt++;
	    }
	    else
	    {
		//once we just skip a valley point    
		if(downCnt > 0)
		{
		    //count the candys at the down side, no count the top
		    result += downCnt*(downCnt +1)/2;
		    if(downCnt >= upCnt)  //upCnt must be greater than downCnt for cosumption!!!
		    {
			result += downCnt - upCnt + 1;  //adjust the missed upCnt 
		    }
		    downCnt = 0;
		    upCnt = 1;
		}
		upCnt = (ratings[i] == ratings[i-1]) ? 1:upCnt+1;
		result += upCnt; //upCnt is added here!!
	    }
	}

	//if we finished on downside
	if(downCnt > 0)
	{
	    result += downCnt * (downCnt + 1)/2;
	    //adjust the missed upCnt
	    if(downCnt >= upCnt) result += downCnt - upCnt + 1;
	}
	return result;
    }
};



















