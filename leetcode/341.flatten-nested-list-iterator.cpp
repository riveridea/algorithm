/*
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator
 *
 * algorithms
 * Medium (42.25%)
 * Total Accepted:    50K
 * Total Submissions: 118.3K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * 
 * Example 2:
 * Given the list [1,[4,[6]]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,4,6].
 * 
 * 
 */
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<NestedInteger> store;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
	//use a stack to store the nested integers 
	if(nestedList.size() == 0) 
	{
	    return;
	}
	for(int i = nestedList.size() - 1; i >= 0; i--)
	{
	    //cout << "push stack " << endl;
	    store.push(nestedList[i]); 
	}
    }

    bool hasNext() {
	while(!store.empty()) 
	{
	    NestedInteger s = store.top();
	    if(s.isInteger())
	    {
		//cout << s.getInteger() << endl;
		return true;
	    }
	   
	    store.pop(); 
	    vector<NestedInteger> childs = s.getList();
	    for(int i = childs.size() - 1; i >= 0; i--)
	    {
		store.push(childs[i]);
	    }
	}
	return false;
    }

    int next() {
	int result = store.top().getInteger();
	store.pop();
	return result; 
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
