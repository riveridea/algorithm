/*
 * [444] Sequence Reconstruction
 *
 * https://leetcode.com/problems/sequence-reconstruction/description/
 *
 * algorithms
 * Medium (19.63%)
 * Total Accepted:    13.1K
 * Total Submissions: 66.6K
 * Testcase Example:  '[1,2,3]\n[[1,2],[1,3]]'
 *
 * Check whether the original sequence org can be uniquely reconstructed from
 * the sequences in seqs. The org sequence is a permutation of the integers
 * from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest
 * common supersequence of the sequences in seqs (i.e., a shortest sequence so
 * that all sequences in seqs are subsequences of it). Determine whether there
 * is only one sequence that can be reconstructed from seqs and it is the org
 * sequence.
 * 
 * Example 1:
 * 
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3]]
 * 
 * Output:
 * false
 * 
 * Explanation:
 * [1,2,3] is not the only one sequence that can be reconstructed, because
 * [1,3,2] is also a valid sequence that can be reconstructed.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * org: [1,2,3], seqs: [[1,2]]
 * 
 * Output:
 * false
 * 
 * Explanation:
 * The reconstructed sequence can only be [1,2].
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
 * 
 * Output:
 * true
 * 
 * Explanation:
 * The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original
 * sequence [1,2,3].
 * 
 * 
 * 
 * Example 4:
 * 
 * Input:
 * org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]
 * 
 * Output:
 * true
 * 
 * 
 * 
 * 
 * UPDATE (2017/1/8):
 * The seqs parameter had been changed to a list of list of strings (instead of
 * a 2d array of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
	//use BFS to detect if this cases happens
	//in one iteratior of bfs, two adjacent nodes are discovered 
	//and in-degrees are decreadsed both to zero, this mean we have 
	//two options to construct the topological sort results
	//thus, the orig sequence is not unique
        if (seqs.size() == 0) return false;
        int n = org.size(), count = 0;

        //compute the in-degrees, also the graph
	    unordered_map<int, int> in_degress;
	    unordered_map<int, unordered_set<int> > graph;
	    for(auto seq : seqs)
	    {
	        if(seq.size()) in_degress[seq[0]]; //make sure seq[0] in th
	        for(int i = 1; i < seq.size(); i++)
	        {
		        if (seq[i] < 1 || seq[i] > n) return false;

		        //adding edges and update the indgrees
		        unordered_set<int> &adjList = graph[seq[i-1]];
		        if(i > 0 && adjList.find(seq[i]) == adjList.end())
		        {
		            adjList.insert(seq[i]);
		            in_degress[seq[i]]++;
		        }
	        }	 
	    }

	//now bfs with a queue
	queue<int> numq;
	for(auto node : in_degress)
	{
	    if(node.second == 0)
	        numq.push(node.first);
	}

	while(!numq.empty())
	{
	    int node = numq.front();
	    numq.pop();
	    //count++; //a new topological sorted node

	    //if we still have node in the numq, means
	    //more than nodes with zero in_degree
	    //thus more than one topsort result exist
	    if(!numq.empty() || node != org[count++])
		    return false;

	    for(auto neigh : graph[node])
	    {
		    if(--in_degress[neigh] == 0)
		        numq.push(neigh);
	    }
	}

    if(count != in_degress.size() || count != org.size())
        return false;
        
	return true;
    }
};

