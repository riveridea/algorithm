/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (30.22%)
 * Total Accepted:    153.7K
 * Total Submissions: 508.6K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	//scan from two direction simutaneouly, find the intervals without overlapping and put to the result
	//for overlapped, update the start and end of the newInterval every time for next comparison
	//keep the left and right, for sort	
	int n = intervals.size();
	//if(n == 0)
	//{
	//    return {newInterval};
	//}

	int s = newInterval.start;
	int e = newInterval.end;

	vector<Interval> left;
	vector<Interval> right;
	for(auto i : intervals)
	{
	    if(i.end < s)
		left.push_back(i);
	    else if(i.start > e)
		right.push_back(i);
	    else
	    {
		//update the s and e
		s = min(i.start, s);
		e = max(i.end, e);
	    }
	}

	Interval ins(s,e);
	left.push_back(ins);
	left.insert(left.end(), right.begin(), right.end());
	return left;
    }
};






























