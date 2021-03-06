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

const int INF = 1e18;

vvi g;
vi sz;
int n;

void calc_sz(int c, int p){
    int c_sz = 1;
    for(int nei: g[c]){
        if(nei == p) continue;
        calc_sz(nei, c);
        c_sz += sz[nei];
    }
    sz[c] = c_sz;
}

int find_cent(int c, int p){
    for(int nei: g[c]){
        if(nei == p) continue;
        if(sz[nei] > n/2) return find_cent(nei, c);
    }
    return c;
}


void solve(){
    cin >> n;
    g.resize(n);
    sz.resize(n);
    rep(n-1){
        int u, v; cin >> u >> v; u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    calc_sz(0, -1);
    cout << find_cent(0, -1)+1 << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}