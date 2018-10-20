/*
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (43.82%)
 * Total Accepted:    117.8K
 * Total Submissions: 268.8K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 * A gray code sequence of n has size = 2n, which for n = 0 the size is 20 =
 * 1.
 * Therefore, for n = 0 the gray code sequence is [0].
 * 
 * 
 */
class Solution {
public:
    vector<int> grayCode(int n) {
	//backtracking way
	//first find the aswner for the bit except the highest bit,
	//then flip the highest bit and find the answer for the rest bit again
	vector<int> result;
	bitset<32> bits;

	backtrack(bits, result, n);
	return result;
    }
private:
    void backtrack(bitset<32> &bits, vector<int> &result, int pos) 
    {
	if(pos == 0) 
	{
	    //got the answer with last bit
	    result.push_back(bits.to_ulong());
	}
	else
	{
	    backtrack(bits, result, pos-1); // process the 0 - k-2 bits with highest bit same
	    bits.flip(pos-1); //flip the highest bit and try again
	    backtrack(bits, result, pos-1);
	}
    }
};
