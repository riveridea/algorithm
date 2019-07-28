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
	vector<int> in_degress(n, 0);
	vector<unordered_set<int> > graph;
	for(auto seq : seqs)
	{
	    for(int i = 0; i < seqs.size(); i++)
	    {
		if (seq[i] < 1 || seq[i] > n) return false;

		//adding edges and update the indgrees
		unordered_set<int> adjList = graph[seq[i-1]];
		if(i > 0 && 
		   adjList.find(seq[i]) == adjList.end())
		{
		    adjList.insert(seq[i]);
		    in_degress[seq[i]]++;
		}
	    }	 
	}

	//now bfs with a queue
	queue<int> numq;
	numq.push(org[0]); //suppose the first node of orig
	if(in_degress[org[0]] > 0) return false;

	int count = 0;
	while(!numq.empty())
	{
	    int node = numq.front();
	    numq.pop();
	    count++; //a new topological sorted node

	    //if we still have node in the numq, means
	    //more than nodes with zero in_degree
	    //thus more than one topsort result exist
	    if(!numq() || numq[count-1] != org[count-1])
		return false;

	    for(auto neigh : graph[node])
	    {
		if(--in_degree[neigh] == 0)
		    numq.push(neigh);
	    }
	}

	return true;
    }
};
