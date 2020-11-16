#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int> 
#define iii tuple<int,int,int>
#define vi vector<int> 
#define vvi vector<vector<int>> 

vvi mat;
int n,m,k;

int max_sum(int row){
    vector<priority_queue<int>> modk(k);
    for(int j=0; j<m;j++){
        modk[mat[row][j]%k].push(mat[row][j]);
    }
    priority_queue<ii> sum;
    for(int i=0; i<k;i++){
        if(modk[i].empty())
            continue;
        int n1 = modk[i].top();
        modk[i].pop();
        if(i == 0 && modk[i].empty())
            sum.emplace(modk[i].top() + modk[k-i].top(),i);
        if(modk[(k-i)%k].empty())
            continue;
        int n2 = modk[(k-i)%k].top();
        modk[(k-i)%k].pop();
        sum.emplace(modk[i].top() + modk[k-i].top(),i);
    }
}


int main(){
    cin >> n >> m >> k;
    mat.resize(n);
    for(int i=0; i<n; i++){
        mat[i].resize(m);
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    int sum=0;
    for(int i=0; i<n;i++){
        sum+=max_sum(i);
    }

    cout << sum << endl;

    return 0;
}