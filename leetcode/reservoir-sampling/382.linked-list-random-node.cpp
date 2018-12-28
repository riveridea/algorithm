/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 *
 * https://leetcode.com/problems/linked-list-random-node/description/
 *
 * algorithms
 * Medium (48.41%)
 * Total Accepted:    47.3K
 * Total Submissions: 97.6K
 * Testcase Example:  '["Solution","getRandom"]\n[[[1,2,3]],[]]'
 *
 * Given a singly linked list, return a random node's value from the linked
 * list. Each node must have the same probability of being chosen.
 * 
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you?
 * Could you solve this efficiently without using extra space?
 * 
 * 
 * Example:
 * 
 * // Init a singly linked list [1,2,3].
 * ListNode head = new ListNode(1);
 * head.next = new ListNode(2);
 * head.next.next = new ListNode(3);
 * Solution solution = new Solution(head);
 * 
 * // getRandom() should return either 1, 2, or 3 randomly. Each element should
 * have equal probability of returning.
 * solution.getRandom();
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
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
	this->head = head; 
    }
    
    /** Returns a random node's value. */
    int getRandom() {
	//this is a reservoir sampling algorithm
	//Note, your operation can be controlled by any possibilty controlled by a rand() function
	//in this problem, every time you can only keep 1 element as result, the question is keep whom?
	//suppose we already have n-1 numbers processed, and each numer is selected equally, thus each number 
	//is kept as result in probabily of 1/(n-1). When the nth elements comes in, we need to output a number
	//that is sure to be 1/(n). How? we have two options, ether we select this new element with 1/(n) problity
	//or we abandon it and pick the existing one. The previous one is 1/n, but how about the next otpion?
	//Actually, as the problily of keeping the old one is 1-1/n = (n-1)/n, also the old is selected in previous
	//operation in probailty 1/(n-1), so far the keeping the old one is still (n-1)/n * 1/(n-1) = 1/n
	
	//so the solution is to generate a random number between 1 and n, each time we are processing the nth sample.
	//then determin to keep the current result or to replace the current result with the nth element.
	ListNode* curr = head;
	int result = 0;
	int count = 0;
	while(curr != nullptr)
	{
	    count++;
	    int pick = rand()%count + 1;
	    result = pick == count ? curr->val : result; 
	    curr = curr->next;
	}
	return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
