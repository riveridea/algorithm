/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (43.84%)
 * Total Accepted:    46.9K
 * Total Submissions: 107K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 * 
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * 
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
	//this is a graph problem and can be solved by union-find structure
	//equations is set of edges
	//we need to define vertices in which each vertice has its own absolute value
	
	unordered_map<string, vertice*> map; //vertices, indexed by the string
	vector<double> res;

	//step 1, construct the graph and initialize the union-find data structure
	//each vertice's parent should be calculated and the absolution vale can also be 
	//determined
	for(int i = 0; i < equations.size(); i++)
	{
	    string s1 = equations[i].first; 
	    string s2 = equations[i].second;
	    //actually here we do 2 things - construct the vertices and union the vertices on the same edge
	    //s1/s2 = values[i]
	    if(map.count(s1) == 0 && map.count(s2) == 0)
	    {
		//std::cout << s1 << " w1 " << s2 << endl;
		
		map[s1] = new vertice();
		map[s2] = new vertice();
		
		map[s1]->value = values[i];
		map[s2]->value = 1;
		map[s1]->parent = map[s2]; 	
	    }
	    else if(map.count(s1) == 0)
	    {
		//std::cout << s1 << " w2 " << s2 << endl;
		map[s1] = new vertice();

		map[s1]->value = map[s2]->value * values[i]; 
		map[s1]->parent = map[s2];
	    }
	    else if(map.count(s2) == 0)
	    {
		//std::cout << s1 << " w3 " << s2 << endl;
		map[s2] = new vertice();

		map[s2]->value = map[s1]->value / values[i];
		map[s2]->parent = map[s1]; 
	    }
	    else // union the two sets actually 
	    {
		//std::cout << s1 << " w4 " << s2 << endl;
		unionVertices(map[s1], map[s2], values[i], map);
	    }
	}

	    //find the answers
        for(auto query : queries)
        {
            //check if valid answer exists
            if(map.count(query.first) == 0 || map.count(query.second) == 0)
            {
                //std::cout << query.first << " and1 " << query.second << endl;
                res.push_back(-1);
            }
            else if(findParent(map[query.first]) != findParent(map[query.second]))
            {
                //std::cout << query.first << " and2 " << query.second << endl;
                res.push_back(-1);
            }
            else
            {
                //std::cout << query.first << " and3 " << query.second << endl;
                res.push_back(map[query.first]->value/map[query.second]->value);
            }
        }
        return res;
    }
private:
    struct vertice{
	vertice * parent;
	double value = 0.0;
	vertice(){parent = this;}
    };


    vertice * findParent(vertice *v)
    {
	if(v->parent == v) return v;
	
	return findParent(v->parent);

	//v->parent =  findParent(v->parent);
	//return v->parent; 
    }

    void unionVertices(vertice *v1, vertice *v2, double value, unordered_map<string, vertice*>& map)
    {
	//first find the parent for v1 and v2
	vertice *parent1 = findParent(v1);
	vertice *parent2 = findParent(v2);

	double ratio = v2->value * value / v1->value;
	//adjust the absolute value for all vertices with parent1
	for(auto it = map.begin(); it != map.end(); it++)
	{
	    if(findParent(it->second) == parent1)
		it->second->value *= ratio;
	}

	//union them
	parent1->parent = parent2;
    }
};
