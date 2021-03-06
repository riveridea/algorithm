/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 *
 * https://leetcode.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (39.08%)
 * Total Accepted:    24.5K
 * Total Submissions: 62.1K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * A gene string can be represented by an 8-character long string, with choices
 * from "A", "C", "G", "T".
 * 
 * Suppose we need to investigate about a mutation (mutation from "start" to
 * "end"), where ONE mutation is defined as ONE single character changed in the
 * gene string.
 * 
 * For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
 * 
 * Also, there is a given gene "bank", which records all the valid gene
 * mutations. A gene must be in the bank to make it a valid gene string.
 * 
 * Now, given 3 things - start, end, bank, your task is to determine what is
 * the minimum number of mutations needed to mutate from "start" to "end". If
 * there is no such a mutation, return -1.
 * 
 * Note:
 * 
 * 
 * Starting point is assumed to be valid, so it might not be included in the
 * bank.
 * If multiple mutations are needed, all mutations during in the sequence must
 * be valid.
 * You may assume start and end string is not the same.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AACCGGTA"
 * bank: ["AACCGGTA"]
 * 
 * return: 1
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * start: "AACCGGTT"
 * end:   "AAACGGTA"
 * bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
 * 
 * return: 2
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * start: "AAAAACCC"
 * end:   "AACCCCCC"
 * bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
 * 
 * return: 3
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        //this is the same as word ladder
        //use BFS, to get the shortest path
        //and because need to count the path, the iteravtive Queue needs to 
        //be iterated to size each time
        int len = start.size();
        if(!len) return 0;

        unordered_set<string> bank_set;
        for(auto s: bank){
            bank_set.insert(s);
        }

        unordered_set<string> v;
        queue<string> q; 

        unordered_map<char, vector<char>> nexts;
        nexts['A'] = {'C', 'G', 'T'};
        nexts['C'] = {'A', 'G', 'T'};
        nexts['G'] = {'C', 'A', 'T'};
        nexts['T'] = {'C', 'G', 'A'};

        q.push(start);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                //if(curr == end) return level;
                for(int i = 0; i < curr.size(); i++){
                    string post = curr;
                    for(auto n: nexts[curr[i]]){
                        curr[i] = n;
                        if(bank_set.find(curr) != bank_set.end() &&
                           v.find(curr) == v.end())
                        {
                            if(curr == end) return level+1; //put here to skip unessary push
                            q.push(curr);    
                            v.insert(curr);
                        }
                    }
                    curr = post;
                }
            }
            level++;
        }
        return -1;
    }
};




