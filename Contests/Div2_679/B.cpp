#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n, m; cin >> n >> m;
    vvi a(n);
    vvi c(n*m+1);
    vvi r(n);
    for(int i=0; i<n;i++){
        r[i].resize(m);
        for(int j=0; j<m; j++){
            cin >> r[i][j];
        }
    }
    for(int i=0; i<m;i++){
        int b;
        cin >> b;
        c[b].push_back(b);
        for(int j=1; j<n; j++){
            int t; cin >> t;
            c[b].push_back(t);
        }
    }

    int first_row;
    for(int i=0; i<n; i++){
        int f = r[i][0];
        if(!c[f].empty())
            first_row = i;
    }
    vvi o(n);
    for(int i=0; i<n; i++){
        o[i].resize(m);
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            o[j][i] = c[r[first_row][i]][j];
            //cout << c[r[first_row][i]][j] << " ";
        }
        //cout << endl;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << o[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}