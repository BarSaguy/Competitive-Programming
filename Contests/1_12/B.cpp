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
const int MOD = 1000000007;
 
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
vi cost;
vvi g;
vvi gt;
vi tin;
vii tout;
vi visited;
 
int t;
 
void dfs(int c){
    if(visited[c]) return;
    visited[c] = 1;
    tin[c] = t;
    t++;
    for(auto nei: g[c]){
        dfs(nei);
    }
    tout[c] = {-t,c};
    t++;
}
 
ii dfsT(int c){
    if(visited[c]) return {INF, 0};
    visited[c] = 1;
    int m = cost[c];
    int cnt = 1;
    for(auto nei: gt[c]){
        ii r = dfsT(nei);
        if(m == r.first){
            cnt += r.second;
        }
        else if(m  > r.first){
            m = r.first;
            cnt = r.second;
        }
    }
    return {m, cnt};
}
 
void solve(){
    int n; cin >> n;
    cost.resize(n, 0);
    g.resize(n);
    gt.resize(n);
    tin.resize(n, 0);
    tout.resize(n);
    visited.resize(n, 0);
    for(int i=0; i<n; i++) cin >> cost[i];
    int m; cin >> m;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v; u--;v--;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
 
    t = 0;
    for(int i=0; i<n; i++){
        dfs(i);
    }
 
    for(int i=0; i<n; i++) visited[i] = 0;
    sort(all(tout));
    int ans = 0;
    int comb = 1;
    for(int i=0; i<n; i++){
       ii r = dfsT(tout[i].second);
       if(r.first == INF) continue;
       ans += r.first;
       comb = comb * r.second % MOD;
    }
    cout << ans <<" " << comb << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}