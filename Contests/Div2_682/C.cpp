#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>

const int INF = 1e18;

vvi a;
vvi b;



void solve(){
    int n, m; cin >> n >>m;
    a.clear();
    b.clear();
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++){
        a[i].resize(m);
        b[i].resize(m, 0);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    //int t=1;
    for(int i=0; i<t; i++) solve();
    return 0;
}