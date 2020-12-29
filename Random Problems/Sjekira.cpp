#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>

const int INF = 1e18;

vvi g;
vi t;
vii t_sorted;
vi visited;
vii edges;


struct DSU{
    vi p;
    vi sz;
    vi mx;
    void init(int n){
        p.resize(n);
        sz.resize(n);
        mx.resize(n);
        for(int i=0; i<n; i++){p[i] = i; sz[i] = 1;mx[i] = t[i];}
    }

    int find(int a){
        if(p[a] == a) return a;
        return p[a]=find(p[a]);
    }

    int find_max(int a){
        a = find(a);
        return mx[a];
    }

    void uni(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a, b);
            p[b] = a;
            if(mx[a] < mx[b]) mx[a] = mx[b];
            sz[a] += sz[b];
        }
    }

};

DSU d;

void solve(){
    int n; cin >> n;
    visited.resize(n, 0);
    for(int i=0; i<n; i++){
        int a; cin >> a;
        t.push_back(a);
        t_sorted.push_back({-a, i});
    }
    sort(all(t_sorted));
    g.resize(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;

    for(int i=0; i<n; i++){
        visited[t_sorted[i].second] = 1;
        for(auto nei: g[t_sorted[i].second]){
            if(visited[nei]) continue;
            edges.push_back({t_sorted[i].second, nei});
        }
    }
    d.init(n);

    for(int i=n-2; i>=0; i--){
        int a = edges[i].first, b = edges[i].second;
        ans += d.find_max(a);
        ans += d.find_max(b);
        d.uni(a, b);
    }

    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}