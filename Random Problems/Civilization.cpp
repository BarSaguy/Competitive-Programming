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

const int INF = 1e18;

struct DSU{
    vi p;
    vi sz;
    void init(int n){
        p.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){p[i] = i; sz[i] = 1;}
    }

    int find(int a){
        if(p[a] == a) return a;
        return p[a]=find(p[a]);
    }

    void uni(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a, b);
            p[b] = a;
            sz[a] += sz[b];
        }
    }

};

vvi g;
vi cand_v;
vi cand_d;
vi visited;
int n,m,q; 
int max_d;
int max_v;

int idx = 0;

void dfs(int c, int dep){
    if(visited[c] >= idx) return;
    visited[c] = idx;
    if(dep > max_d) {max_v = c;max_d = dep;}
    for(auto nei: g[c]) dfs(nei, dep+1);
}

void find_diam(int c){
    max_d=0;
    max_v=-1;
    int s, e;
    idx = 0;
    dfs(c, 0);
    s = max_v;
    max_d=0;
    idx = 1;
    dfs(s, 0); 
}

void solve(){
    cin >> n >> m >> q;
    g.resize(n);

    cand_d.resize(n, -1);

    DSU d;
    d.init(n);

    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        d.uni(u, v);
    }
    visited.resize(n, -1);
    for(int i=0; i<n; i++){
        int p = d.find(i);
        if(cand_d[p] == -1){
            find_diam(p);
            cand_d[p] = max_d;
        }
    }

    for(int i=0; i<q; i++){
        int op; cin >> op;
        if(op == 1){
            int u; cin >> u; u--;
            cout << cand_d[d.find(u)] << endl;
        }
        else{
            int u, v; cin >> u >> v; u--;v--;
            int p1 = d.find(u);
            int p2 = d.find(v);
            if(p1 != p2){
                if(cand_d[p1] > cand_d[p2]){
                    cand_d[p1] = max(cand_d[p1], cand_d[p1]/2+cand_d[p1]%2 + 1 + cand_d[p2]/2+cand_d[p2]%2);
                    cand_d[p2] = cand_d[p1];
                }
                else{
                    cand_d[p2] = max(cand_d[p2], cand_d[p1]/2+cand_d[p1]%2 + 1 + cand_d[p2]/2+cand_d[p2]%2);
                    cand_d[p1] = cand_d[p2];
                }

                d.uni(u, v);
            }
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}