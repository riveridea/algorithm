/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.66%)
 * Total Accepted:    665.8K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* prev = NULL, *head = NULL;
	int carry = 0; 
	while(l1 || l2)
	{
	    int sum = (l1 && l2)? l1->val + l2->val + carry : l1 ? l1->val + carry : l2->val + carry; 
	    carry = sum / 10;
	    int cval = sum%10;
	    ListNode* node = new ListNode(cval);
	    if(prev != NULL) 
	    {
		prev->next = node;	
	    }
	    else
	    {
		head = node;
	    }

	    if(l1) l1 = l1->next;
	    if(l2) l2 = l2->next;
	    prev = node;
	}
	
	if(carry) 
	{
	    ListNode* node = new ListNode(carry);
	    prev->next = node;
	}
	
	return head;
    }
};
