#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vb vector<bool>

vvi g;
vb visited;
int e;
int max_depth;
int e_depth;

void dfs(int s,int d, int dest){
    if(visited[s]) return;
    visited[s] = true;
    if(s == dest){
        e_depth = d;
        return;
    }
    if(d > max_depth){
        max_depth = d;
        e = s;
    }
    for(auto nei: g[s]){
        dfs(nei, d+1,dest);
    }
}

int find_diameter(){
    e = 0;
    max_depth = 0;
    for(int i=0; i<visited.size();i++){
        visited[i] = false;
    }
    dfs(0, 0, -1);
    max_depth = 0;
    for(int i=0; i<visited.size();i++){
        visited[i] = false;
    }
    dfs(e, 0, -1);
    return max_depth;
}

void solve(){
    int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
    a--;b--;
    g.clear();
    g.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(db <= 2*da){
        cout << "Alice" << endl;
        return;
    }

    visited.clear();
    visited.resize(n, false);
    int dia = find_diameter();
    visited.clear();
    visited.resize(n, false);
    dfs(a,0,b);
    int dist_a_b = e_depth;
    if(dist_a_b <= da){
        cout << "Alice" << endl;
        return;
    }
    if(dia <= 2*da){
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}