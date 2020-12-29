#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define pqii priority_queue<ii>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>

const int INF = 1e18;
// const int MOD = 998244353;

// int pow(int a, int p){
//     if(p == 0) return 1;
//     if(p == 1) return a;
//     int r = pow(a, p/2);
//     int ans = r * r % MOD;
//     if(p%2)
//         ans  = ans * a % MOD;
//     return ans;
// }

// int inv(int n){
//     return pow(n, MOD-2);
// }

vvi g;
vi visited;

ii dfs(int c){
    if(visited[c]) return {-INF, 0};
    visited[c] = 1;
    ii r = {0, c};
    for(auto nei: g[c]){
        ii cr = dfs(nei);
        cr.first += 1;
        if(r.first < cr.first){
            r = cr;
        }
    }
    return r;
}


void solve(){
    int n; cin >> n;
    g.resize(n);
    visited.resize(n, 0);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ii r = dfs(0);
    int ans = r.first;
    for(int i=0; i<n; i++) visited[i] = 0;
    r = dfs(r.second);
    ans = r.first;
    cout << ans*3 << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}