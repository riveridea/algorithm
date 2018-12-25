/*
 * @lc app=leetcode id=369 lang=cpp
 *
 * [369] Plus One Linked List
 *
 * https://leetcode.com/problems/plus-one-linked-list/description/
 *
 * algorithms
 * Medium (55.25%)
 * Total Accepted:    29.4K
 * Total Submissions: 53.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-negative integer represented as non-empty a singly linked list
 * of digits, plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 * 
 * 
 * Example :
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * 
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
    ListNode* plusOne(ListNode* head) {
	//this problem can be solved by recursive,
	//but i consider an iterative method, by reversing the linked list and reverse back in-place
	ListNode * curr = head;
	ListNode * prev = nullptr, *next = nullptr;
	//reverse unitl the last digit
	while(curr != nullptr)	
	{
	    next = curr->next;
	    curr->next = prev;
	    prev = curr;
	    curr = next;
	}

	//the prev is non-negative pointing the last digit
	int carry = 1;
	curr = prev;
	//next = nullptr; //no need, as this time, next is nullptr
	while(curr != nullptr)
	{
	    int sum = curr->val + carry;
	    carry = sum/10;
	    curr->val = sum%10;
	    
	    //reverse again
	    curr = curr->next;
	    prev->next = next;
	    next = prev;
	    prev = curr;
	}
	//at this time, next is the point to the head of the linked list
	if(carry > 0) //we need a new node to carry new head
	{
	    ListNode* new_head = new ListNode(1);
	    new_head->next = next;
	    next = new_head;
	}
	return next;
    }
};
