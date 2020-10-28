#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>

const int INF = 1e9;

vvi g;
vi cost;
vi ans;
queue<int> q;
vector<bool> visited;

void bfs(int s, bool a){
    q.push(s);
    q.push(-1);
    int cnt=0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t == -1){
            cnt++;
            if(!q.empty())
                q.push(-1);
            continue;
        }
        if(visited[t]) continue;
        if(a && t/2 < ans.size() && (ans[t/2]%2 != t%2))
            continue;
        visited[t] = true;
        cost[t] = cnt;
        for(auto nei : g[t]){
            q.push(nei);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    g.resize(2*n+2);  // Night and day nodes
    cost.resize(2*n+2, INF);
    ans.resize(n);
    visited.resize(2*n+2, false);

    g[0].push_back(2*n); 
    g[1].push_back(2*n);
    g[2*n+1].push_back(2*n-2);
    g[2*n+1].push_back(2*n-1);

    for(int i=0; i<m; i++){
        int u,v,t; cin >> u >> v >> t;
        u--;v--;
        int idx;
        if(t==0){
            idx = 2*u;
        }
        else{
            idx = 2*u+1;
        }
        g[2*v].push_back(idx);
        g[2*v+1].push_back(idx);
    }

    bfs(2*n+1, false);
    for(int i=0; i<n;i++){
        if(cost[2*i] > cost[2*i+1])
            ans[i] = 0;
        else
            ans[i] = 1;   
    }
    cost.clear();
    cost.resize(2*n+2, INF);
    visited.clear();
    visited.resize(2*n+2, false);
    bfs(2*n+1, true);
    if(cost[2*n] == INF)
        cout << -1 << endl;
    else
        cout << cost[2*n] - 2 << endl;
    for(int i=0; i<n; i++){
        if(i == n-1)
            cout << ans[i] << endl;
        else
            cout << ans[i];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}