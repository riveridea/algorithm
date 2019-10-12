/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 *
 * https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
 *
 * algorithms
 * Medium (35.50%)
 * Total Accepted:    17.2K
 * Total Submissions: 47.9K
 * Testcase Example:  '[1,3,5,4]\n[1,2,3,7]'
 *
 * We have two integer sequences A and B of the same non-zero length.
 * 
 * We are allowed to swap elements A[i] and B[i].  Note that both elements are
 * in the same index position in their respective sequences.
 * 
 * At the end of some number of swaps, A and B are both strictly increasing.
 * (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... <
 * A[A.length - 1].)
 * 
 * Given A and B, return the minimum number of swaps to make both sequences
 * strictly increasing.  It is guaranteed that the given input always makes it
 * possible.
 * 
 * 
 * Example:
 * Input: A = [1,3,5,4], B = [1,2,3,7]
 * Output: 1
 * Explanation: 
 * Swap A[3] and B[3].  Then the sequences are:
 * A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
 * which are both strictly increasing.
 * 
 * 
 * Note:
 * 
 * 
 * A, B are arrays with the same length, and that length will be in the range
 * [1, 1000].
 * A[i], B[i] are integer values in the range [0, 2000].
 * 
 * 
 */
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        //this problem the DP logic is a little weird
        //because the operation at i-1 could impact the operation at i
        //you cannot just simply use the answer at i-1 to detemine i
        //at both i-1 and i we can swap or not swap, according to the
        //relationship of all the 4 elements, a[i-1], a[i] and b[i-1], b[i]
        //suppose no_swap_1 is the minimum swaps at i-1 if a[i-1] and b[i-1]
        //is not swap, and swap_1 is the minimum swaps at i-1 if a[i-1] and b[i-1]
        //is swapped, so is no_swap_2, swap_2 at i.
        //you will see the no_swap_2/swap_2 is updated based on no_swap_1/swap_1
        int n_swap_1 = 0, swap_1 = 1;
        for(int i = 1; i < A.size(); i++){
            int n_swap_2 = INT_MAX, swap_2 = INT_MAX;
            //as the problem says it is guarrenteed to make the possible
            //only below two cases exsit
            if(A[i-1] < A[i] && B[i-1] < B[i]){
                n_swap_2 = min(n_swap_2, n_swap_1);
                swap_2 = min(swap_2, swap_1+1);
            }
            if(A[i-1] < B[i] && B[i-1] < A[i]){
                n_swap_2 = min(n_swap_2, swap_1);
                swap_2 = min(swap_2, n_swap_1+1);
            }
            n_swap_1 = n_swap_2;
            swap_1 = swap_2;
        }
        return min(n_swap_1, swap_1);
    }
};
