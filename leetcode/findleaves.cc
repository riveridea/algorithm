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
		if(parents.empty())
		{
		    //reach the root
		    vector<int> final(curr->val, 1);
		    result.push_back(final);
		    break;
		}
                TreeNode* parent = parents.top();
		s.pop();
		cout << " parent = " << parent->val << " ";
		cout << " leaf = " << curr->val << endl;

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
		//delete curr;
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
		cout << "[";
		for(auto each : each_result)
		{
		    cout << each;
		}
		cout << "]" << endl;
		each_result.clear();
                if(!parents.empty())
                {
		    TreeNode *nextPar = parents.top();
		    cout << "next parent restarted " << nextPar->val << endl;
                    s.push(nextPar);
                    parents.pop();
                }
		else
		{
		    vector<int> final(root->val, 1);
		    result.push_back(final);
		}
            }
        }

	return result;
    }
};

int main()
{
    //build tree 
    vector<int> array = {1};
    vector<TreeNode> tree;
    for(int i = 0; i < array.size(); i++)
    {
	tree.push_back(TreeNode(0));
    }
    TreeNode *root =  &tree[0];

    for(int i = 0; i < array.size(); i++)
    {
	TreeNode *curr = &tree[i];
	curr->val = array[i];
	cout << curr->val << " ";
	if(i*2 + 1 < array.size())
	{
	    curr->left = &tree[i*2 + 1]; 
	    curr->left->val = array[i*2 + 1];
	}
	if(i*2 + 2 < array.size())
	{
	    curr->right = &tree[i*2 + 2]; 
	    curr->right->val = array[i*2 + 2];
	}
    }
    
    cout << " root is " << root->val << endl;
    if(root->left)
	cout << " root left is " << root->left->val << endl;
    if(root->right)
	cout << " root right is " << root->right->val << endl;
    TreeNode *left = root->left;
    if (left && left->left)
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
	    cout << each_element;
	}
	cout << " ]" << endl;
    }
}
