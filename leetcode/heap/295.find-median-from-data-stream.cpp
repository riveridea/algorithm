/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (38.85%)
 * Total Accepted:    131.9K
 * Total Submissions: 339.1K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */
class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //each time we need to keep balance of lo and hi
        //lo at most has 1 more element than hi
        lo.push(num);

        hi.push(lo.top());
        lo.pop();

        if(lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        //use the two heaps, 
        //lo - Max Heap, storing the elements lower than the minimum of Hi
        //Hi - Min Heap, storing the elemtns bigger than the maximum of lo
        //if lo and hi has the same number of elements, 
        // median = (lo.top() + hi.top()) * 0.5
        //if lo has 1 more element than hi
        // median = lo.top()
        return (lo.size() > hi.size()) ? (double)lo.top() : (lo.top() + hi.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
