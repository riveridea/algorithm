/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 *
 * https://leetcode.com/problems/number-of-recent-calls/description/
 *
 * algorithms
 * Easy (69.48%)
 * Total Accepted:    29K
 * Total Submissions: 41.7K
 * Testcase Example:  '["RecentCounter","ping","ping","ping","ping"]\n[[],[1],[100],[3001],[3002]]'
 *
 * Write a class RecentCounter to count recent requests.
 * 
 * It has only one method: ping(int t), where t represents some time in
 * milliseconds.
 * 
 * Return the number of pings that have been made from 3000 milliseconds ago
 * until now.
 * 
 * Any ping with time in [t - 3000, t] will count, including the current ping.
 * 
 * It is guaranteed that every call to ping uses a strictly larger value of t
 * than before.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs =
 * [[],[1],[100],[3001],[3002]]
 * Output: [null,1,2,3,3]
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Each test case will have at most 10000 calls to ping.
 * Each test case will call ping with strictly increasing values of t.
 * Each call to ping will have 1 <= t <= 10^9.
 * 
 * 
 * 
 * 
 * 
 */
class RecentCounter {
private:
    vector<int> times;
    vector<int>::iterator up;
public:
    RecentCounter() : times(10001, INT_MAX){ 
	up = times.begin(); //the first pos is not used
    }
    
    int ping(int t) {
	*++up = t;

	int last = t - 3000;
	last = last < 0 ? 0 : last;
	vector<int>::iterator low = lower_bound(times.begin() + 1, times.end(), last);
						//--------------//
						//the first element is not used

	return up - low + 1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
