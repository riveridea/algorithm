#include <unordered_set>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print_grid(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    cout << "{\n";
    for(int i = 0; i < n; i++){
        cout << "[";
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << "]\n";
    }
    cout << "}\n";
}

void updateGrid(vector<vector<int>>& grid, unordered_set<int>& dones, int& ones){
    vector<vector<int>> cgrid = grid;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int pos = i*m+j;
            if(dones.find(pos) == dones.end()){
                if(cgrid[i][j] == 1){
                    if(i - 1 >= 0) 
                    {
                        if(grid[i-1][j] == 0){
                            grid[i-1][j] = 1;
                            ones++;
                        }
                    }
                    if(i + 1 < n){
                        if(grid[i+1][j] == 0){
                            grid[i+1][j] = 1;
                            ones++;
                        }
                    }
                    if(j - 1 >= 0){
                        if(grid[i][j-1] == 0){
                            grid[i][j-1] = 1;
                            ones++;
                        }
                    }
                    if(j + 1 < m){
                        if(grid[i][j+1] == 0){
                            grid[i][j+1] = 1;
                            ones++;
                        }
                    }
                    
                    dones.insert(pos);
                }
            }
        }
    }
}

int calc_max_days(vector<vector<int>>& grid){
    int days = 0;

    unordered_set<int> dones;

    int n = grid.size();
    if(!n) return INT_MAX;
    int m = grid[0].size();
    if(!m) return INT_MAX;
    int ones = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1) ones++;
        }
    }
   
    print_grid(grid);
    while(ones < n*m){
        days++;
        updateGrid(grid, dones, ones);
        print_grid(grid);
    }
    return days;
}

int main(){
   vector<vector<int>> grid = {
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
   };

   cout << calc_max_days(grid);
}
