#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>
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



// dest, weight
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
void solve(){
    int n, m; cin >> n >> m;
    g.resize(4*n);  // 4 Graphs, 0-regular, 1-max, 2-min, 3-good
    min_dist.resize(4*n, INF);
    rep(m){
        int u, v, w; cin >> u >> v >> w; u--;v--;
        rep(j, 4){
            g[4*u+j].pb({4*v+j,w});
            g[4*v+j].pb({4*u+j,w});
        }
        g[4*u].pb({4*v+1,0});
        g[4*v].pb({4*u+1,0});
        g[4*u].pb({4*v+2,2*w});
        g[4*v].pb({4*u+2,2*w});
        g[4*u].pb({4*v+3,w});
        g[4*v].pb({4*u+3,w});

        g[4*u+1].pb({4*v+3,2*w});
        g[4*v+1].pb({4*u+3,2*w});

        g[4*u+2].pb({4*v+3,0});
        g[4*v+2].pb({4*u+3,0});
    }
    dijkstra(0);
    rep(i, 1, n){
        cout << min_dist[4*i+3] << " ";
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}