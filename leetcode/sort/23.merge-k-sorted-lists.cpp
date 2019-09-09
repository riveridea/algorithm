/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.89%)
 * Total Accepted:    444.1K
 * Total Submissions: 1.2M
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
	//let us do the divide and conquer 
	//try again with merging the two list with interval
	//interval starts from 2^0 to 2^m < n, n is the size of lists
	int n = lists.size();
	if(n == 0) return NULL;
	int interval = 1;
	while(interval < n){
	    for(int i = 0; i < n - interval; i += 2*interval)
	    {
		lists[i] = merge2Lists(lists[i], lists[i+interval]);
	    }
	    interval *= 2;
	}
	
	return lists[0];
    }

private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
	if(!l1) return l2;
	if(!l2) return l1;
	
	ListNode* head = NULL;
	ListNode* prev = NULL, *curr = NULL;
	while(l1 && l2){
	    if(l1->val < l2->val){
		if(prev == NULL) head = l1;
		curr = l1;
		l1 = l1->next;
	    }
	    else{
		if(prev == NULL) head = l2;
		curr = l2;
		l2 = l2->next;
	    }
	    if(prev != NULL) prev->next = curr;
	    prev = curr;
	}
	//if not stop at the same time
	prev->next = l1?l1:l2;

	return head;
    }
};
