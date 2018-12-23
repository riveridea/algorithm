/*
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits
 *
 * algorithms
 * Medium (61.72%)
 * Total Accepted:    96K
 * Total Submissions: 155.5K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * 
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 * 
 * 
 * Follow up:
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount  in c++ or in any other language.
 * 
 * 
 * 
 * Credits:Special thanks to @ syedee  for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    vector<int> countBits(int num) {
	//I here use a clear method,not the i&(i-1) to update, as that is a little hard to understand
	//we see the number in different areas
	//1. 0 - 2^0
	//2. 2^1 - 2^2-1
	//3. 2^2 - 2^3-1
	//4. 2^3 - 2^4-1
	//5. 2^4 - 2^5-1
	//etc.
	//it is easy to find the number of integers of area i is the sum of all its previous areas
	//also, the count of bits for a number in area i is corresponding to the same sequence of
	//of the all preivous areas plus 1. 
	//we can define a vector<int> for each area, we add the count bits for these numbers
	//then the next area can use the count in the current result, using a indicator from the 
	//begin of result to the latest one
	if (num == 0) return {0};
	if (num == 1) return {0, 1};
	if (num == 2) return {0, 1, 1};
	vector<int> res{0, 1, 1, 2};

	int area = 2; 
	int idx = 4;
	while(idx <= num)
	{
	    //process each area each time
	    int j = 0;
	    for(idx = pow(2, area); idx < pow(2, area+1); ++idx, ++j)
	    {
		if(idx > num) break;
		res.push_back(res[j] + 1);
	    }
	    area++;	
	}
	return res;
    }
};
