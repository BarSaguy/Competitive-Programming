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
vi b;
vi dist;

void dfs(int c){
    if(visited[c]) return;
    visited[c] = 1;
    for(auto nei: g[c]){
        if(!visited[nei])
            dist[nei] = dist[c] + 1;
        dfs(nei);
    }
}


void solve(){
    int n; cin >> n;
    g.resize(n);
    visited.resize(n, 0);
    dist.resize(n, 0);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi inc(n, 0);
    dfs(0);
    int m = dist[0];
    int s = 0;
    for(int i=0; i<n; i++){
        if(m < dist[i]){
            b.clear();
            b.push_back(i);
            m = dist[i];
            s = i;
        }
        if(m == dist[i]) b.push_back(i);
    }
    for(int i=0; i<b.size();i++) inc[b[i]] = 1;
    b.clear();
    for(int i=0; i<n; i++){ visited[i] = 0; dist[i] = 0;}
    dfs(s);
    m = dist[0];
    for(int i=0; i<n; i++){
        if(m < dist[i]){
            b.clear();
            b.push_back(i);
            m = dist[i];
        }
        if(m == dist[i]) b.push_back(i);
    }
    for(int i=0; i<b.size();i++) inc[b[i]] = 1;
    int ans = m;
    for(int i=0; i<n; i++){
        if(inc[i]) cout << ans+1 << endl;
        else cout << ans << endl;
    }
    //cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}