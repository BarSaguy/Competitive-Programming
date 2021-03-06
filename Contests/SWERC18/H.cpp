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

vi min_dist;

void dijkstra(int source){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0LL,source);
    min_dist[source] = 0;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        if(top.x != min_dist[top.y]) continue;
        for(auto nei: g[top.y]){
            if(min_dist[nei.x] > min_dist[top.y] + nei.y){
                min_dist[nei.x] = min_dist[top.y] + nei.y;
                pq.emplace(min_dist[nei.x], nei.x);
            }
        }
    }
}

#define iii pair<int, ii>
#define viii vector<iii>

void solve(){
    int n, m; cin >> n >> m;
    // n =5;
    g.resize(n);
    min_dist.resize(n, INF);
    rep(m){
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    viii d(n);
    dijkstra(0);
    rep(n) d[i].x = min_dist[i], min_dist[i] = INF;
    dijkstra(1);
    rep(n) d[i].y.x = min_dist[i], min_dist[i] = INF;
    dijkstra(2);
    rep(n) d[i].y.y = min_dist[i], min_dist[i] = INF;
    // d[0] = {0, {2, 2}};
    // d[1] = {2, {0, 2}};
    // d[2] = {2, {2, 0}};
    // d[3] = {1, {1, 1}};
    // d[4] = {1, {1, 1}};
    sort(all(d));

    vi u(n, 1);
    int j = 0;
    rep(n-1){
        if(d[j] == d[i+1]) u[j]++, u[i+1]=0;
        else j = i+1;
    }
    // unique(all(d));
    set<ii> s;
    s.insert(d[0].y);
    int ans = u[0];
    rep(i, 1, n){
        if(!u[i]) continue;
        auto iter = s.upper_bound(d[i].y);
        if(iter != s.begin()){
            iter = prev(iter);
            ii cur = *iter;
            if(cur.y > d[i].y.y){
                s.insert(d[i].y);
            }
            else{
                continue;
            }
        }
        else{
            s.insert(d[i].y);
        }
        //if(!u[i])
        ans += u[i];
        iter = next(s.lower_bound(d[i].y));
        while(iter != s.end()){
            auto tmp = next(iter);
            if(d[i].y.y < iter->y){
                s.erase(iter);
            }
            else break;
            iter = tmp;
        }
        
    }

    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}