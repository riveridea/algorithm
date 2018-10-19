class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->columns = vector<int>(n, 0);
        this->principal_diag = vector<int>(2*n, 0);
        this->counter_diag = vector<int>(2*n, 0);
        
        vector<vector<string> > result;
        vector<int> C(n, 0);
        
        dfs(0, n, C, result);
        return result;
    }
private:
    vector<int> columns;
    vector<int> principal_diag;
    vector<int> counter_diag;
    
    void dfs(int row, int n, vector<int> &C, vector<vector<string> > &result){
        vector<string> solution;
        if(row == n){//we have reached to the last line, the solutino exists
            for(int i=0; i<n; i++){
                string s (n, '.');
                for(int j=0; j<n; j++){
                    if(j == C[i]) s[j] = 'Q';
                }
                //s[C[i]] = 'Q';
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }
        
        for(int j=0; j<n; j++){//scan by columns
            bool ok = columns[j] == 0 && principal_diag[row+j] == 0
                          && counter_diag[row - j + n - 1] == 0;
            if(ok){
                C[row] = j;
                
                columns[j] = 1;
                principal_diag[row+j] = 1;
                counter_diag[row - j + n - 1] = 1;
                dfs(row+1, n, C, result);
                
                //Do not forget to resume the values
                columns[j] = 0;
                principal_diag[row +j] = 0;
                counter_diag[row - j + n - 1] = 0;                
            }
        }
    }
};
