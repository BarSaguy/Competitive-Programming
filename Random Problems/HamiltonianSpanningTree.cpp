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
#define pb push_back

const int INF = 1e18;

vvi g;
vi deg;
vi visited;

vvi dp;

// dp[c][0] - 0 edge
// dp[c][1] - 1 edges
// dp[c][2] - 2 edges

void dfs(int c, int p){
    int s=0;
    int cnt = 0;
    int neig;
    dp[c][0] = dp[c][1] = dp[c][2] = INF;
    for(int nei: g[c]){
        if(nei == p) continue;
        dfs(nei, c);
        neig = nei;
        cnt++;
    }
    if(cnt == 0){
        dp[c][0] = 1;
        return;
    } else if(cnt == 1){
        dp[c][0] = min(min(dp[neig][2], dp[neig][1]), dp[neig][0])+1;
        dp[c][1] = min(dp[neig][0], dp[neig][1]);
        return;
    }
    s = 0;
    int p1=INF,p2=INF;
    int idx1=0, idx2=0;
    int a1=INF, a2=INF;
    for(int nei: g[c]){
        if(nei == p) continue;
        int v = min(min(dp[nei][0], dp[nei][1]), dp[nei][2]);
        s += v;
        int a = min(dp[nei][0], dp[nei][1])-v;
        if(p1 >= a){idx2=idx1;p2=p1;p1=a;idx1=nei;}
        else if(p2 > a){p2=a;idx2=nei;}
    }
    dp[c][0] = s+1;
    dp[c][1] = s + p1;
    dp[c][2] = s + p1 + p2 - 1;
}

void solve(){
    int n, x, y; cin >> n >> x >> y;
    g.resize(n);
    deg.resize(n,0);
    dp.resize(n);
    rep(n) dp[i].resize(3, 0);
    visited.resize(n,0);
    int m_deg = 0;
    rep(n-1){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
        if(m_deg < max(deg[u],deg[v]))m_deg=max(deg[u],deg[v]);
    }
    if(x >= y){
        if(m_deg == n-1) cout << (n-2)*y+x;
        else cout << (n-1)*y << endl;
        return;
    }
    int s=0;
    dfs(0, -1);
    int j = min(min(dp[0][0], dp[0][1]), dp[0][2])-1;
    cout << j*y + (n-1-j)*x << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}