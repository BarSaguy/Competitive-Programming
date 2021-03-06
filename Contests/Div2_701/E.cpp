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
#define eb emplace_back
#define chkmax(a, b) a=max(a,b);
#define chkmin(a, b) a=min(a,b);


const int INF = 1e18;

vvi g;
vi a;

vi dp;
vi max_v;
vi min_v;

void dfs(int c, int p, int d){
    if(d > 0){
        dp[c] = dp[p] + max(max_v[d] - a[c], a[c] - min_v[d]);
    }
    for(int nei: g[c]){
        if(nei == p) continue;
        dfs(nei, c, d+1);
    }
}

void calc_vals(int c, int p, int d){

    chkmax(max_v[d], a[c]);
    chkmin(min_v[d], a[c]);

    for(int nei: g[c]){
        if(nei == p) continue;
        calc_vals(nei, c, d+1);
    }
}

void solve(){
    int n; cin >> n;
    g.clear();
    g.resize(n);
    a.resize(n);
    dp.resize(n, 0);

    rep(n-1){
        int u = i+1;
        int v; cin >> v; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    a[0] = 0;
    rep(n-1){
        cin >> a[i+1];
    }

    max_v.resize(n);
    max_v.assign(n, -INF);
    min_v.resize(n);
    min_v.assign(n, INF);
    calc_vals(0, -1, 0);
    rep(n) dp[i] = 0;
    dfs(0, -1, 0);

    int ans = 0;
    rep(n) chkmax(ans, dp[i]);
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}