/*
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (42.42%)
 * Total Accepted:    32.2K
 * Total Submissions: 75.9K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * Given a char array representing tasks CPU need to do. It contains capital
 * letters A to Z where different letters represent different tasks.Tasks could
 * be done without original order. Each task could be done in one interval. For
 * each interval, CPU could finish one task or just be idle.
 * 
 * However, there is a non-negative cooling interval n that means between two
 * same tasks, there must be at least n intervals that CPU are doing different
 * tasks or just be idle. 
 * 
 * You need to return the least number of intervals the CPU will take to finish
 * all the given tasks.
 * 
 * Example 1:
 * 
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * 
 * 
 * 
 * Note:
 * 
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * 
 * 
 */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	//the basic idea is to construct k-1 frames where k is the maximum frequence
    	//of the task, then fill the rest of the task into the frame
    	//the length of each frame would be n+1
    	//if the rest of the tasks are not as many as enough to fill the frames
    	//the idle would be fitted
    	//if no idle tasks are needed, you will find all the tasks are used, thus the 
    	//answer is tasks.size()
    	//one more thing, you still need an additional frame which are filled by all the 
    	//tasks with the same frequence as the maximum one     

	unordered_map<char, int> mp;
	int count = 0;
     	for(auto e : tasks)
     	{
	    //find the maximum frequence
	    mp[e]++;
	    count = max(count, mp[e]);
  	}
	//now we get the max frequence in count
	//set the candidated answer
	int ans = (count - 1)*(n + 1);
	//update the answer based on how many tasks with max frequence
	for(auto e : mp) 
	{
	    if(e.second == count) ans++;
	}
	//finally, updat the answer if no idle task is needed (tasks can fill all the frames)
	return max((int)tasks.size(), ans);
    }
};
