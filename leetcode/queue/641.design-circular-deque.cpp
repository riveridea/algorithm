/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 *
 * https://leetcode.com/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (49.96%)
 * Total Accepted:    9K
 * Total Submissions: 18.1K
 * Testcase Example:  '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * Design your implementation of the circular double-ended queue (deque).
 * 
 * Your implementation should support following operations:
 * 
 * 
 * MyCircularDeque(k): Constructor, set the size of the deque to be k.
 * insertFront(): Adds an item at the front of Deque. Return true if the
 * operation is successful.
 * insertLast(): Adds an item at the rear of Deque. Return true if the
 * operation is successful.
 * deleteFront(): Deletes an item from the front of Deque. Return true if the
 * operation is successful.
 * deleteLast(): Deletes an item from the rear of Deque. Return true if the
 * operation is successful.
 * getFront(): Gets the front item from the Deque. If the deque is empty,
 * return -1.
 * getRear(): Gets the last item from Deque. If the deque is empty, return
 * -1.
 * isEmpty(): Checks whether Deque is empty or not. 
 * isFull(): Checks whether Deque is full or not.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to
 * be 3
 * circularDeque.insertLast(1);            // return true
 * circularDeque.insertLast(2);            // return true
 * circularDeque.insertFront(3);            // return true
 * circularDeque.insertFront(4);            // return false, the queue is full
 * circularDeque.getRear();              // return 2
 * circularDeque.isFull();                // return true
 * circularDeque.deleteLast();            // return true
 * circularDeque.insertFront(4);            // return true
 * circularDeque.getFront();            // return 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in Deque library.
 * 
 * 
 */
class MyCircularDeque {
private:
    vector<int> buffer;
    int count; // number of elements
    int capacity; // actual physical space size
    int front; // position before the first element
    int rear;  // position right after the last element
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : buffer(k, 0), count(0), capacity(k), front(k-1), rear(0) {
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
	if(isFull()) return false;

	buffer[front] = value;
	front = (front - 1 + capacity)%capacity;
	count++;

	return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
	if(isFull()) return false;

	buffer[rear] = value;
	rear = (rear + 1)%capacity;
	count++;

	return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
	if(isEmpty()) return false;

	front = (front + 1)%capacity;
	count--;

	return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
	if(isEmpty()) return false;
	
	rear = (rear - 1 + capacity)%capacity;
	count--;
	
	return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
	if(isEmpty()) return -1;
        
	return buffer[(front + 1)%capacity];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
	if(isEmpty()) return -1;

	return buffer[(rear - 1 + capacity)%capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
	return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
	return count == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
