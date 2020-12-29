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

int dfs(int start, int cur){
    if(visited[cur]) return 0;
    visited[cur] = 1;
    int ret = 0;
    for(auto nei: g[cur]){
        if(nei == start && cur != start) return 1;
        ret = max(ret, dfs(start, nei));
    }
    return ret;
}

void solve(){
    int n, m; cin >> n >> m;
    vi u(m);
    vi v(m);
    g.clear();
    visited.clear();
    g.resize(n);
    visited.resize(n, 0);
    for(int i=0; i<m; i++) {
        cin >> u[i] >> v[i];
        u[i]--;v[i]--;
        g[u[i]].push_back(v[i]);
    }
    int ans = m;
    for(int i=0; i<m; i++){
        if(u[i] == v[i]) ans--;
    }
    for(int i=0; i<n; i++) ans += dfs(i, i);
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}