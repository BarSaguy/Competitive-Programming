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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)

const int INF = 1e18;

#define vvii vector<vii>

vvii g;
vi h;
int cat, mouse;
int cnt_vis;
vi path;

void calc_h(int c, int p){
    for(auto nei: g[c]){
        if(nei.y == p) continue;
        calc_h(nei.y, c);
        chkmax(h[c], h[nei.y] + 1);
    }
}

void check_vis(int c, int p){
    cnt_vis++;
    for(auto nei: g[c]){
        if(nei.y == p) continue;
        check_vis(nei.y, c);
    }
}

int dfs_to_mouse(int c, int p){
    if(c == mouse){
        return 1;
    }
    for(auto nei: g[c]){
        if(nei.y == p) continue;
        int r = dfs_to_mouse(nei.y, c);
        if(r){
            path[c] = 1;
            return 1;
        }
    }
    return 0;
}

void solve(){
    int n,m; cin >> n >> m; m--;
    g.clear();
    h.clear();
    h.resize(n);
    g.resize(n);
    path.resize(n);
    mouse = m;
    cat = 0;
    rep(n-1){
        int u, v; cin >> u >> v;u--;v--;
        g[u].pb({i, v});
        g[v].pb({i, u});
    }
    rep(n) sort(all(g[i])), reverse(all(g[i]));
    cnt_vis = 0;
    check_vis(0, -1);
    if(cnt_vis != n){
        cout << -1 <<endl;
        return;
    }
    calc_h(0, -1);
    dfs_to_mouse(0, -1);
    int ans = 0;
    while(mouse != cat){
        ans++;
        int dest;
        cout << "mouse: " << mouse << endl;
        cout << "Cat: " << cat << endl;
        if(g[mouse][0].y != cat){
            dest = g[mouse][0].y;
        }
        else if(g[mouse].size() == 1) break;
        else dest = g[mouse][1].y;
        if(h[mouse] > h[dest]){
            path[mouse] = 1;
        } else{
            path[mouse] = 0;
        }

        mouse = dest;
        path[cat] = 0;
        for(auto nei: g[cat]){
            if(path[nei.y]){
                cat = nei.y;
                break;
            }
        }
        
    }

    cout << "ans: " << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}