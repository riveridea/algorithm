/*
 * [683] K Empty Slots
 *
 * https://leetcode.com/problems/k-empty-slots/description/
 *
 * algorithms
 * Hard (33.32%)
 * Total Accepted:    25.5K
 * Total Submissions: 76.5K
 * Testcase Example:  '[1,3,2]\n1'
 *
 * 
 * There is a garden with N slots. In each slot, there is a flower. The N
 * flowers will bloom one by one in N days. In each day, there will be exactly
 * one flower blooming and it will be in the status of blooming since then.
 * 
 * 
 * 
 * Given an array flowers consists of number from 1 to N. Each number in the
 * array represents the place where the flower will open in that day.
 * 
 * 
 * 
 * For example, flowers[i] = x means that the unique flower that blooms at day
 * i will be at position x, where i and x will be in the range from 1 to N.
 * 
 * 
 * 
 * Also given an integer k, you need to output in which day there exists two
 * flowers in the status of blooming, and also the number of flowers between
 * them is k and these flowers are not blooming.
 * 
 * 
 * 
 * If there isn't such day, output -1.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * flowers: [1,3,2]
 * k: 1
 * Output: 2
 * Explanation: In the second day, the first and the third flower have become
 * blooming.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * flowers: [1,2,3]
 * k: 1
 * Output: -1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given array will be in the range [1, 20000].
 * 
 * 
 */
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        //firstly tranform the flowers to days, representing the blooming day at each position
        if (!flowers.size()) return -1;
        vector<int> days(flowers.size());
        int day = 1;
        for(auto pos: flowers){
            days[--pos] = day++;
        }
        
        int left = 0, right = k + 1;
        int result = INT_MAX;
        for(int i = 0; right < days.size(); i++)
        {
            //continue unitl the i does not satisfy the days[i] > days[left] && days[i] > days[right]
            if(days[i] < days[left] || days[i] <= days[right]){
                if(i == right)//find consective series of i between left and right, 
                {
                    result = min(result, max(days[left], days[right]));
                }
                //udpate left and right
                left = i; 
                right = left + k + 1;
            }
        }
        
        return (result == INT_MAX)?-1:result;
    }
};
