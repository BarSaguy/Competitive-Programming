#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Not finished, just implementation

int main(){
    int t; cin >> t;
    for(int r=0; r<t;r++){
        int n; cin >> n;
        vector<string> grid;
        pair<int, int> idx1, idx2;
        int c = 0;
        grid.resize(n);
        for(int i=0; i<n; i++){
            cin >> grid[i];
        }
        if(n > 1){
            if(grid[0][1] != grid[1][0]){
                if(grid[n-1][n-2] != grid[n-2][n-1]){
                    c = 2;
                    if(grid[0][1] == grid[n-1][n-2]){
                        idx1 = make_pair(0, 1);
                    }
                }
                else
                {
                    int val = grid[n-1][n-2];
                    c = 1;
                    if(grid[0][1] == val){
                        idx1 = make_pair(0, 1);
                    }
                    else
                    {
                        idx1 = make_pair(1, 0);
                    }
                    
                }
                
                if(grid[0][1] == 1){
                    idx1 =  make_pair(0, 1);
                }
                
            }
        }
    }

    return 0;
}