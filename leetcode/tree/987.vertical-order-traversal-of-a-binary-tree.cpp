/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 *
 * https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (33.15%)
 * Total Accepted:    21.3K
 * Total Submissions: 64.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the vertical order traversal of its nodes
 * values.
 * 
 * For each node at position (X, Y), its left and right children respectively
 * will be at positions (X-1, Y-1) and (X+1, Y-1).
 * 
 * Running a vertical line from X = -infinity to X = +infinity, whenever the
 * vertical line touches some nodes, we report the values of the nodes in order
 * from top to bottom (decreasing Y coordinates).
 * 
 * If two nodes have the same position, then the value of the node that is
 * reported first is the value that is smaller.
 * 
 * Return an list of non-empty reports in order of X coordinate.  Every report
 * will have a list of values of nodes.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * 
 * Input: [3,9,20,null,null,15,7]
 * Output: [[9],[3,15],[20],[7]]
 * Explanation: 
 * Without loss of generality, we can assume the root node is at position (0,
 * 0):
 * Then, the node with value 9 occurs at position (-1, -1);
 * The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
 * The node with value 20 occurs at position (1, -1);
 * The node with value 7 occurs at position (2, -2).
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [1,2,3,4,5,6,7]
 * Output: [[4],[2],[1,5,6],[3],[7]]
 * Explanation: 
 * The node with value 5 and the node with value 6 have the same position
 * according to the given scheme.
 * However, in the report "[1,5,6]", the node value of 5 comes first since 5 is
 * smaller than 6.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The tree will have between 1 and 1000 nodes.
 * Each node's value will be between 0 and 1000.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<TreeNode*, vector<int>> mp;

class Solution {
public:
    ~Solution(){
        //as you used the global data, need to clear the map for
        //the next test case :(
        mp.clear();
    }
    static bool compare(TreeNode* a, TreeNode* b){
        //firstly compare the y 
        //then compare the val
        int ya = mp[a][1], yb = mp[b][1];
        return (ya == yb)? a->val < b->val : ya < yb;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //it is very natural to think about to calculate each 
        //position of the node, and put each one to the 
        //hash map indexed by location 
        vector<vector<int>> res;
        if(!root) return res;

        //do DFS 
        stack<TreeNode*> s;
        s.push(root);
        mp[root] = {0,0};
        int minx = INT_MAX, maxx = INT_MIN;
        while(s.empty() == false){
            TreeNode* p = s.top(); s.pop();
            int x = mp[p][0], y = mp[p][1];
            minx = min(x, minx);
            maxx = max(x, maxx);
            if(p->left){
                s.push(p->left);
                mp[p->left].push_back(x - 1);
                mp[p->left].push_back(y + 1);
            }
            if(p->right){
                s.push(p->right);
                mp[p->right].push_back(x + 1);
                mp[p->right].push_back(y + 1);
            }
        }

        //output the result
        //cout << "maxx:" << maxx << " minx" << minx << endl;
        int len = maxx - minx + 1;
        res.resize(len);
        vector<vector<TreeNode*>> t_res(len);
        for(auto node : mp){
            t_res[node.second[0] - minx].push_back(node.first); 
        }
    
        for(auto& v : t_res){
            sort(v.begin(), v.end(), compare);
            int x = mp[v[0]][0];
            for(auto node : v){
                res[x - minx].push_back(node->val);
            } 
        }
        return res;
    }
};
