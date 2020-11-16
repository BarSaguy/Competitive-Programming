#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vvi g;
vi c;
vi visited;
void dfs(int cur, int col1, int col2){
    if(visited[cur]) return;
    visited[cur] = true;
    int color = 1;
    for(auto nei: g[cur]){
        if(visited[nei]) continue;
        if(color == col1 || color == col2)
            color++;
        if(color == col1 || color == col2)
            color++;
        c[nei] = color;
        dfs(nei, color, col1);
        color++;
    }
}


void solve(){
    int n; cin >> n;
    g.resize(n);
    c.resize(n);
    visited.resize(n, false);
    int ans = 0;
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        if(g[u].size()+1 > ans)
            ans = g[u].size()+1;
        if(g[v].size()+1 > ans)
            ans = g[v].size()+1;
    }
    cout << ans << endl;
    c[0] = 1;
    dfs(0, 1, -1);
    for(int i=0; i<n; i++){
        if(i == n-1)
            cout << c[i] << endl;
        else
            cout << c[i] << " ";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}