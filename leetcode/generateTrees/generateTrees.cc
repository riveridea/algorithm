#include <iostream>
#include <vector>
#include <string>

using namespace std;
//HARD See notes and recite the code
/*
	Given n, generate all structurelly unique BST's that store all values in [1,n]
*/


/**
 * Definition for binary tree*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return generate(1, 0);
        return generate(1, n);
    }
private:
    vector<TreeNode *> generate(int start, int end){
    	//Most important, the vector here represents the all possible subtrees by the vector
    	//elements as the root of the possible subtree
    	//thus we create different level of vector for each recursive call of generate
        vector<TreeNode *> subTree;
        if (start > end){
            subTree.push_back(nullptr);
            return subTree;
        }
        for (int k = start; k<=end; k++){
            vector<TreeNode*> leftSubs = generate(start, k-1); //return all left subtrees
            vector<TreeNode*> rightSubs = generate(k+1, end); //return all right subtrees
            //for all left and right subtrees, the root needs to be allocated f(k-start)*f(end-k) times
            for (auto i: leftSubs){
                for(auto j: rightSubs){
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};

int main(){
	Solution sln;
	vector<TreeNode*> trees = sln.generateTrees(3);
	for (auto node: trees){
		std::cout << node->val;
		if (node->left)	    std::cout << node->left->val;
	    if (node->right)    std::cout << node->right->val;
	    std::cout << std::endl;
	}
	printf("end\n");
}
