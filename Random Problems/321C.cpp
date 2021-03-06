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
vi sz;
vi visited;
vi is_cent;
vi par;

void calc_sz(int c, int p){
    sz[c] = 1;
    par[c] = p;
    for(int nei: g[c]){
        if(nei == p) continue;
        calc_sz(nei, c);
        sz[c] += sz[nei];
    }
}

int find_cent(int c, int p, int n, int cur_val){
    for(int nei: g[c]){
        if(nei == p || is_cent[nei]) continue;
        if(sz[nei] > n/2){
            int cent = find_cent(nei, c, n, cur_val);
            sz[c] -= sz[cent];
            return cent;
        }
    }
    is_cent[c] = cur_val;
    return c;
}

void rec(int c, int n, int cur_val){
    if(cur_val > 'Z') return;
    if(is_cent[c]) return;
    int cent = find_cent(c, -1, sz[c], cur_val);
    for(int nei: g[cent]){
        if(par[cent] == nei) continue;
        rec(nei, sz[nei], cur_val+1);
    }
    rec(c, sz[c], cur_val+1);
}


void solve(){
    int n; cin >> n;
    g.resize(n);
    sz.resize(n, 0);
    visited.resize(n, 0);
    is_cent.resize(n, 0);
    par.resize(n, 0);
    rep(n-1){
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    calc_sz(0, -1);

    rec(0, n, 'A');
    rep(n) if(!is_cent[i]){cout << "Impossible" << endl;return;}
    rep(n) cout << (char)is_cent[i] << " ";
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}