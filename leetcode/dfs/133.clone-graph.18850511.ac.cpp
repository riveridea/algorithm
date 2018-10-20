/*
 * [133] Clone Graph
 *
 * https://leetcode.com/problems/clone-graph/description/
 *
 * algorithms
 * Medium (25.08%)
 * Total Accepted:    175.1K
 * Total Submissions: 698.2K
 * Testcase Example:  '{}'
 *
 * Given the head of a graph, return a deep copy (clone) of the graph. Each
 * node in the graph contains a label (int) and a list
 * (List[UndirectedGraphNode]) of its neighbors. There is an edge between the
 * given node and each of the nodes in its neighbors.
 * 
 * 
 * OJ's undirected graph serialization (so you can understand error output):
 * 
 * Nodes are labeled uniquely.
 * We use # as a separator for each node, and , as a separator for node label
 * and each neighbor of the node.
 * 
 * 
 * 
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * 
 * The graph has a total of three nodes, and therefore contains three parts as
 * separated by #.
 * 
 * 
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
 * a self-cycle.
 * 
 * 
 * 
 * 
 * Visually, the graph looks like the following:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    /   \
 * ⁠   0 --- 2
 * ⁠        / \
 * ⁠        \_/
 * 
 * 
 * Note: The information about the tree serialization is only meant so that you
 * can understand error output if you get a wrong answer. You don't need to
 * understand the serialization to solve the problem.
 * 
 * 
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        //breadth first searching using the Queue
        //unordered_map still used to check copied or not, copied will not push into the queue, but need to connected
        if (node == nullptr) return nullptr;
        //map for duplicates checking
        unordered_map<const UndirectedGraphNode *,
                            UndirectedGraphNode *> copied;
        //queue for BFS
        queue<UndirectedGraphNode*> q;
        q.push(node);
        copied[node] = new UndirectedGraphNode(node->label);
        while(!q.empty()){
            UndirectedGraphNode* cur = q.front();
            q.pop();
            for(auto nbr: cur->neighbors){
                if(copied.find(nbr) != copied.end()){//visited neightbor, but because it is undireted graphs, needs connect back
                    copied[nbr]->neighbors.push_back(copied[cur]);
                }
                else{//created new copy
                    copied[nbr] = new UndirectedGraphNode(nbr->label);
                    copied[cur]->neighbors.push_back(copied[nbr]);
                    q.push(nbr);
                }
            }
        }
        
        return copied[node];
    }
};
