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
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, s, n) for (int i = (s); i < (n); i++)
#define repr(...) GET_MACRO(__VA_ARGS__, repr3, repr2, repr1)(__VA_ARGS__)
#define repr1(n) for (int i = (n)-1; i >= 0; i--)
#define repr2(i, n) for (int i = (n)-1; i >= 0; i--)
#define repr3(i, n, s) for (int i = (n)-1; i >= (s); i--)
#define x first
#define y second
#define pb push_back

const int INF = 1e18;

vvi g;
vi result;
vi visited;
vi color;
int cnt=0;


void dfs(int cur){
    if(visited[cur]) return;
    visited[cur] = 1;
    cnt++;
    if(color[cur] == 0){
        color[cur] = 1;
        result.pb(cur);
        for(auto nei: g[cur]) color[nei] = 2;
    }
    for(auto nei: g[cur]){
        dfs(nei);
    }
}



void solve(){
    int n, m; cin >> n >> m;
    g.clear();
    color.clear();
    visited.clear();
    result.clear();
    cnt=0;
    color.resize(n, 0);
    g.resize(n);
    rep(m){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    visited.resize(n, 0);
    dfs(0);
    if(cnt != n){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << result.size() << endl;
        rep(result.size()) cout << result[i]+1 <<" ";
        cout << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}