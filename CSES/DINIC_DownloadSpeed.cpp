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


struct FlowEdge{
    int u, v;
    int cap,flow=0;
    FlowEdge(int u, int v, int cap):u(u),v(v),cap(cap){}
};

struct Dinic{
    const int flow_inf = 1e18;
    vector<FlowEdge> edges;
    vvi adj;
    int n, m=0;
    int s, t;
    vi level, ptr;
    qi q;

    Dinic(int n, int s, int t):n(n), s(s), t(t){
        adj.resize(n);level.resize(n);ptr.resize(n);
    }

    void add_edge(int u, int v, int cap){
        edges.eb(u, v, cap);
        edges.eb(v, u, 0);
        adj[u].pb(m);
        adj[v].pb(m+1);
        m += 2;
    }

    bool bfs(){
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int nei: adj[u]){
                if(edges[nei].cap - edges[nei].flow < 1) continue;
                if(level[edges[nei].v] != -1) continue;
                level[edges[nei].v] = level[u]+1;
                q.push(edges[nei].v);
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int pushed){
        if(pushed == 0) return 0;
        if(u == t) return pushed;
            for (int& cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            int nei = adj[u][cid];
            int v = edges[nei].v;
            if (level[u] + 1 != level[v] || edges[nei].cap - edges[nei].flow < 1)
                continue;
            int tr = dfs(v, min(pushed, edges[nei].cap - edges[nei].flow));
            if (tr == 0)
                continue;
            edges[nei].flow += tr;
            edges[nei ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }

};

void solve(){
    int n, m; cin >> n >> m;
    Dinic d(n, 0, n-1);
    rep(m){
        int u, v, c; cin >> u >> v >> c; u--; v--;
        d.add_edge(u, v, c);
    }
    cout << d.flow() << endl; 
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}