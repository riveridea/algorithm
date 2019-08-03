/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (38.75%)
 * Total Accepted:    82.5K
 * Total Submissions: 213K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * Example:
 * 
 * 
 * Input: [5,2,6,1]
 * Output: [2,1,1,0] 
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 */
class node {
public:
	int val;
	int dups;
	int less_sum; //node less than this one
	node *left;
	node *right;
	node(int v):val(v), dups(1), less_sum(0), left(NULL),right(NULL) {}
};

class Solution {
    node* insert(int num, vector<int>& ans, node* root, int i)
    {
	int& cnt = ans[i];
	node *new_node = NULL;
	if(root == NULL){
	    //this is the first element
	    cnt = 0;
	    new_node = new node(num);
	    return new_node;
	}
	else{
	    node *curr_node = root;
	    node *prev_node = NULL;
	    bool go_right = true;
	    while(curr_node)
	    {
		go_right = true;
		if(curr_node->val == num){
		    cnt += curr_node->less_sum;
		    curr_node->dups++;
		    return root;
		}
		
		prev_node = curr_node;
		if(curr_node->val < num){ //go to the right
		    cnt += curr_node->dups + curr_node->less_sum;
		    curr_node = curr_node->right;	
		}
		else{
		    curr_node->less_sum++;
		    go_right = false;
		    curr_node = curr_node->left;	
		}
	    }
	    
	    curr_node = new node(num);
	    if(go_right)
		prev_node->right = curr_node; 
	    else
		prev_node->left = curr_node;
	}
	return root;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
	//let try the simplest way, BST
	//insert from the most right element to build BST while counting
	//the steps of moving the right
	int n = nums.size();
	vector<int> ans(n,0);
	
	node *bst = NULL; //empty bineary search tree
	for (int i = n-1; i >= 0; i--)
	{
	    //cout << "inserting " << nums[i] << " ";
	    bst = insert(nums[i], ans, bst, i);
	}
	return ans;
    }
};









































