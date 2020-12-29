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
#define all(arr) (arr.begin(), arr.end())
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

const int INF = 1e17;

vi visited;
vi dist;
vvi g;
int rnd = 0;
queue<pair<ii, int>> q;

int dfs(int p, int c, int d){
    if(visited[c] >= rnd) return INF;
    visited[c] = rnd;
    dist[c] = d;
    int ans = INF;
    for(auto nei: g[c]){
        if(visited[nei] >= rnd && nei != p) if(ans > dist[nei] + d+1) ans = dist[nei] + d+1;
        q.push({{nei, d+1},c});
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(n) cin >> a[i];
    vvi cnt(60);
    g.resize(n);
    rep(n){
        int t = a[i];
        int idx=0;
        while(t){
            if(t%2) cnt[idx].push_back(i);
            t /= 2;
            idx++;
        }
    }
    rep(60) if(cnt[i].size() >= 3){cout << 3 << endl; return;}

    rep(60){
        if(cnt[i].size() == 2){
            int u = cnt[i][0];
            int v = cnt[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    int ans = INF;
    visited.resize(n, 0);
    dist.resize(n, INF);
    rep(n){
        rnd++;
        int l = dfs(i, i, 0);
        if(ans > l) ans = l;
        while(q.size() > 0){
            int r = dfs(q.front().second, q.front().first.first, q.front().first.second);
            q.pop();
            if(ans > r) ans = r;
        }
    }
    if(ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}