#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        //try to use the union-find algorithm
        //this union-find utiliy ever been used in Kruskal's algorithm 
        //minimum spanning tree
        //every point is uniquely identified by row_size*x+y
        ancestors.resize(m*n, -1);
        vector<int> result;
        
        //add points now
        int ilands = 0;
        vector<pair<int, int> > offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto point : positions)
        {
            //check each neighbers to see can be connnected 
            //suppose it is a new iland, will decrease if it is not
            ilands++;
            int index = point.first * n + point.second;
	    cout << "curr index:" << index << endl; 
	    ancestors[index] = index;
            for(auto shift : offsets)
            {
                int x = point.first + shift.first, y = point.second + shift.second;
                int neigh_index = x*n + y;
		cout << "x: " << x << ", y: " << y;
		cout << ",ancestors[" << neigh_index <<"]:" << ancestors[neigh_index] <<endl;
                if(x < 0 || x >= m || y < 0 || y >= n || ancestors[neigh_index] == -1)
                    continue;
                
                if (union_nodes(index, neigh_index)) 
		//int rootPos = find_ancestor(index), rootNew = find_ancestor(neigh_index);
		//if(rootPos != rootNew)
		{
		//    ancestors[]
		    ilands--; 
		}
            }
	    cout << "ilands:" << ilands << endl;
            result.push_back(ilands); 
        }
        
        return result;
    }
private:
    vector<int> ancestors;

//utilties to find and union    
    int find_ancestor(int index)
    {
        //if(ancestors[index] == -1)
        //{
        //    //ancestors[index] = index;
        //    return index;
	//}
	//else
	//{
        //    return find_ancestor(ancestors[index]);
        //}
	while(index != ancestors[index])
	{
	    index = ancestors[index];
	    cout << "find " << index << endl;
	}
	return index;
    }
    
    bool union_nodes(int idx1, int idx2)
    {
	cout << "union nodes " << idx1 << " " << idx2 << endl;
        int ancestor1 = find_ancestor(idx1);
	cout << idx1 << "has parent" << ancestor1 << endl;
        int ancestor2 = find_ancestor(idx2);
	cout << idx2 << "has parent" << ancestor2 << endl;
        if(ancestor1 != ancestor2)
	{
            ancestors[ancestor1] = ancestor2;
	    return true;
	}
	else
	    return false;
    }
};

int main()
{
    Solution s;
    int m = 3, n = 3;
    vector<pair<int, int>> poss = 
    {
	make_pair(0, 0),
	make_pair(0, 1),
	make_pair(0, 2),
	make_pair(1, 2),
	make_pair(2, 2),
	make_pair(2, 1),
	//make_pair(1, 1)
	//make_pair(2, 1)
    };

    vector<int> result =  s.numIslands2(m, n, poss);
    for(auto v : result)
	cout << " " << v;
}
