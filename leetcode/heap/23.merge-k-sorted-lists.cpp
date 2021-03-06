/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (31.42%)
 * Total Accepted:    301.1K
 * Total Submissions: 958.3K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	//we don't use priority queue here
	//divid and conque:
	//firt iteration, merge the list and list+interval, interval = 2^0
	//second iteration, merge the list and list+interval, interval = 2^1
	//... interval = 2^2
	//unitl interval >= number of lists
	int n = lists.size();
	if(n==0) return nullptr;
	int interval = 1;
	while(interval < n)
	{
	    //cout << "[" <<"interval =" << interval << "]";
	    for(int i = 0; i < n - interval; i += 2*interval) 
	    {
		if(i+interval < n)
		{
		    lists[i] = merge2lists(lists[i], lists[i+interval]);
		    //cout << i << endl;
		}
	    }
	    interval *= 2;
	}
	return lists[0];
    }
private:
    ListNode* merge2lists(ListNode* l1, ListNode* l2)
    {
	if(!l1) return l2;
	if(!l2) return l1;

	ListNode* curr = NULL, *prev = NULL;
	ListNode* head = NULL;
	while(l1 && l2)
	{
	    if(l1->val < l2->val)
	    {
		if(prev == NULL) head = l1;
		curr = l1;
		l1 = l1->next;
	    }
	    else
	    {
		if(prev == NULL) head = l2;
		curr = l2;
		l2 = l2->next;
	    }
	    if(prev != NULL)
		prev->next = curr; 

	    prev = curr; //store the current minimum to prev
	}

	prev->next = l1 ? l1 : l2;

	ListNode* c = head;
	cout << "{";
	while(c)
	{
	    cout << c->val << "->";
	    c = c->next;
	}
	cout << "}";

	return head;
    
    }
};












