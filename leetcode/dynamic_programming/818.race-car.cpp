/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 *
 * https://leetcode.com/problems/race-car/description/
 *
 * algorithms
 * Hard (36.50%)
 * Total Accepted:    12.8K
 * Total Submissions: 34.9K
 * Testcase Example:  '3'
 *
 * Your car starts at position 0 and speed +1 on an infinite number line.
 * (Your car can go into negative positions.)
 * 
 * Your car drives automatically according to a sequence of instructions A
 * (accelerate) and R (reverse).
 * 
 * When you get an instruction "A", your car does the following: position +=
 * speed, speed *= 2.
 * 
 * When you get an instruction "R", your car does the following: if your speed
 * is positive then speed = -1 , otherwise speed = 1.  (Your position stays the
 * same.)
 * 
 * For example, after commands "AAR", your car goes to positions 0->1->3->3,
 * and your speed goes to 1->2->4->-1.
 * 
 * Now for some target position, say the length of the shortest sequence of
 * instructions to get there.
 * 
 * 
 * Example 1:
 * Input: 
 * target = 3
 * Output: 2
 * Explanation: 
 * The shortest instruction sequence is "AA".
 * Your position goes from 0->1->3.
 * 
 * 
 * 
 * Example 2:
 * Input: 
 * target = 6
 * Output: 5
 * Explanation: 
 * The shortest instruction sequence is "AAARA".
 * Your position goes from 0->1->3->7->7->6.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= target <= 10000.
 * 
 * 
 */
class Solution {
public:
    int racecar(int target) {
        //this can be done by shortest path, like BFS, or dijkstra 
        //here the dynamic programming is used
        
        //it is every hard
        //T[i] is defined the minimum instruction path from start to postion i
        //let us check the last possible postion j
        //1. j < i
        //thus j = (A^m)R.size() = 2^m - 1 then reverse p = (A^q)R.size() = 2^q - 1
        //T[i] = T[i - (j-p)] + m + 1 + q + 1;
        //2. j = i
        //T[i] = m
        //3. j > i
        //(A^m)R(A^q)
        //T[i] = m + 1 + T[j - i]
        vector<int> T(target + 1);

        for(int i = 1; i <= target; i++){
            T[i] = INT_MAX; //!!!!don't forget
            int m = 1, j = 1; //j's updated by m
            //for j < j
            for(; j < i; j = (1<<++m) - 1){
                int q = 0, p = 0;
                for(;p < j; p = (1<<++q)-1)
                    T[i] = min(T[i], m + q + 2 + T[i - j + p]);
            }
            //now j >= i
            if(j == i)
                T[i] = min(T[i], m) ;
            else
                T[i] = min(T[i], m + 1 + T[j-i]);
        }
        return T[target];
    }
};

