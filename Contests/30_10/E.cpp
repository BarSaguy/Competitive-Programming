#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vvii vector<vector<ii>>
#define vb vector<bool>

int n, k , d;

vi ps;
vvii g;
vi ans;
vi visited;
queue<ii> q;

void bfs(){
    //int depth = 0;
    while(!q.empty()){
        ii t =  q.front();
        q.pop();
        //if(t.first == -1){
        //    if(q.empty())
        //        break;
        //    depth++;
        //    q.push({-1, -1});
        //     continue;
        //}
        for(auto nei: g[t.first]){
            if(visited[nei.first] == -1){
                visited[nei.first] = t.second;
                q.push({nei.first, t.second});
            }
            else if(visited[t.first] < visited[nei.first]){
                ans.push_back(nei.second);
            }
        }
    }
}

void solve(){
    cin >> n >> k >> d;
    ps.resize(n, 0);
    g.resize(n);
    visited.resize(n, -1);
    int start;
    for(int i=0; i<k; i++){
        int p; cin >> p;
        p--;
        ps[p] = 1;
        start = p;
    }
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    for(int i=0; i<n; i++){
        if(ps[i]){
            q.push({i, i});
            visited[i] = i;
        }
    }
    //q.push({-1, -1});
    bfs();
    
    cout << ans.size() << endl;
    for(int i=0; i<ans.size();i++){
        if(i == ans.size()-1)
            cout << ans[i]+1 << endl;
        else
            cout << ans[i]+1 << " ";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}