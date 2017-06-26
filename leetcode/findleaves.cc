#include <vector>
#include <stack>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        //try to use DFS to search leaves for each round
        vector<vector<int>> result;
        if(!root) return result;
        
        stack<TreeNode*> s;
        stack<TreeNode*> parents;
        vector<int> each_result;
        
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr = s.top();
	    cout << " start processing stack top " <<  curr->val << endl;
            TreeNode* left = curr->left, *right = curr->right;
            if(left || right)
            {
                //parent
                parents.push(curr);
                s.pop();
		cout << " push " << curr->val << " to parents" << endl;
                if(left)
		{
		    s.push(left);
		    cout << " - push left : " << left->val << endl;
		}                 
		if(right)
		{
		    s.push(right);
		    cout << " - push right: " << right->val << endl;
		}
                
            }
            else
            {
                //find leave
                TreeNode* parent = parents.top();
		cout << " parent = " << parent->val << " ";
		cout << " leaf = " << curr->val << endl;

                //delete the leaf
		if(!parent) break;
                if(curr == parent->left)
                {
		    cout << " curr leaf is " << parent->val << "'s left child " << endl;
                    parent->left = NULL;
                }
                else
                {
		    cout << " curr leaf is " << parent->val << "'s right child " << endl;
                    parent->right = NULL;
                }
                each_result.push_back(curr->val);
		s.pop();
		delete curr;
                //determine parent lost all children
                if(!parent->left && !parent->right)
                    parents.pop();
            }
          
	    if(!s.empty()) 
		cout << "after processig, stack top is " << s.top()->val << endl; 
            if(s.empty())
            {
                //output the each result
		cout << "one round end \n";
                result.push_back(each_result);
                if(!parents.empty())
                {
                    s.push(parents.top());
                    parents.pop();
                }
                else
                {
                    return result;
                }
            }
        }

	return result;
    }
};

int main()
{
    //build tree 
    vector<int> array = {1, 2, 3, 4, 5};
    TreeNode *root = NULL;

    for(int i = 0; i < array.size(); i++)
    {
	TreeNode *curr = new TreeNode(array[i]);
	if(i == 0) root = curr;
	TreeNode *left = NULL, *right = NULL;
	cout << curr->val << " ";
	if(i*2 + 1 < array.size())
	{
	    left = new TreeNode(array[i*2+1]);

	    cout << (left?left->val:0) << " ";
	    curr->left = left; 
	}
	if(i*2 + 2 < array.size())
	{
	    right = new TreeNode(array[i*2 + 2]);
	    cout << (right?right->val:0);
	    curr->right = right;
	}
	cout << endl;
    }
    
    cout << " root is " << root->val << endl;
    cout << " root left is " << root->left->val << endl;
    TreeNode *left = root->left;
    if (left->left)
	cout << " child of left is " << left->left->val << endl;
    else
	cout << " chile of left is NULL" << endl;

    Solution s;
    vector<vector<int>> leaves = s.findLeaves(root);
    for(auto each_result : leaves)
    {
        cout << "[ ";
	for(auto each_element : each_result)
	{
	    cout << each_element << endl;
	}
	cout << " ]" << endl;
    }
}
