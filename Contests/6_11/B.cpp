#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

priority_queue<ii> pq;

vvi g;
vvi gT;
vi ans;
vi degin;
vi mv;
const int INF = 1e18;

void dfs(int cur){
    if(mv[cur] > cur) mv[cur] = cur;
    for(auto nei: gT[cur]){
        if(mv[nei] > mv[cur]) mv[nei] = mv[cur];
    }
}


void solve(){
    int n, m; cin >> n >> m;
    g.resize(n);
    gT.resize(n);
    ans.resize(n);
    degin.resize(n, 0);
    mv.resize(n, INF);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v; u--;v--;
        g[u].push_back(v);
        degin[v]++;
        gT[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        if(degin[i] == 0) pq.push({-mv[i], -i});
        if(g[i].empty()) dfs(i);
    }
    int idx = 1;
    while(!pq.empty()){
        ii t = pq.top(); pq.pop();
        for(auto nei:g[-t.second]){
            degin[nei]--;
            if(degin[nei] == 0) pq.push({-mv[nei], -nei});
        }
        ans[-t.second] = idx;idx++;
    }
    for(int i=0; i<n; i++){
        if(i==n-1)
            cout << ans[i] << endl;
        else
            cout << ans[i] << " ";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}