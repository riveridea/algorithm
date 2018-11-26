/*
 * @lc app=leetcode id=255 lang=cpp
 *
 * [255] Verify Preorder Sequence in Binary Search Tree
 *
 * https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/description/
 *
 * algorithms
 * Medium (42.14%)
 * Total Accepted:    30.4K
 * Total Submissions: 72.1K
 * Testcase Example:  '[5,2,6,1,3]'
 *
 * Given an array of numbers, verify whether it is the correct preorder
 * traversal sequence of a binary search tree.
 * 
 * You may assume each number in the sequence is unique.
 * 
 * Consider the following binary search tree: 
 * 
 * 
 * ⁠    5
 * ⁠   / \
 * ⁠  2   6
 * ⁠ / \
 * ⁠1   3
 * 
 * Example 1:
 * 
 * 
 * Input: [5,2,6,1,3]
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: [5,2,1,3,6]
 * Output: true
 * 
 * Follow up:
 * Could you do it using only constant space complexity?
 * 
 */
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
	//preorder: current -> left -> right
	//for BST, we have decresing firstly going to left then if increasing found, you must reach a right child
	//of the one of the preivous nodes and this parent of this child should be lower bound of the rest of array
	//so if any of the following elements greater than this lower bound will mark as a false
	//remember, the lower bound could be updated each time an new increasing element is found
	if(preorder.empty()) return true;
	
	stack<int> s;
	int lower_bound = INT_MIN;
	cout << "start" << endl;
	for(int i = 0; i < preorder.size(); i++)
	{
	    if(s.empty() || preorder[i] < preorder[i-1])	    
	    {
		//decreasing. 
		if(preorder[i] <= lower_bound)
		{
		    //cout << "1 lb:" << lower_bound << "curr:" << preorder[i];
		    return false; //abnormal found!!
		}
		s.push(preorder[i]);
	    }
	    else
	    {
		//increasing, met a right child, looking for its parent as the lower bound
		while(!s.empty() && s.top() < preorder[i])
		{
		    lower_bound = s.top(); //keep update the lower bound until the parent  
		    //cout << "2 lb:" << lower_bound << "curr:" << preorder[i];
		    s.pop();
		}
		s.push(preorder[i]);
	    }
	}
	//no abnormal found
	return true;
    }
};




































