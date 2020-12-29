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

struct Node{ // space: O(min(Q*logMAX, MAX))
    int l,r,mid; // [l,r)
    int v=0;
    int prop = 0;
    Node *lp=0, *rp=0;
    Node(int l, int r): l(l), r(r), mid((l+r)/2){}
    void add(int x){
        prop+=x;
        v+=(r-l)*x;
    }
    void fix(){
        if (!lp) lp = new Node(l, mid);
        if (!rp) rp = new Node(mid, r);
        if (prop){
            lp->add(prop);
            rp->add(prop);
            prop = 0;
        }
        v = lp->v + rp->v;
    }
    int queryI(int i){
        if (l+1==r){
            return v;
        }
        fix();
        if (i<mid) return lp->queryI(i);
        else return rp->queryI(i);
    }
    int query(int a, int b){ // [a,b)
        if (a>=r || b<=l) return INF;
        if (a<=l && r<=b) return v;
        fix();
        return lp->query(a,b) + rp->query(a,b);
    }
    void updateI(int i, int x){
        if (l+1==r){
            v = x;
            return ;
        }
        fix();
        if (i<mid) lp->updateI(i, x);
        else rp->updateI(i, x);
        fix();
    }
    void update(int a, int b, int x){
        if (a>=r || b<=l) return ;
        if (a<=l && r<=b) {
            add(x);
            return ;
        }
        fix();
        lp->update(a,b,x);
        rp->update(a,b,x);
        fix();
    }
};


vvi g;
vi a;
vi dist;
vi visited;
vi group;
vi add;
vector<Node*> paths;
int cnt = 0;
int sz = 0;
int g_i =0;

void dfs(int cur, int dep){
    if(visited[cur]) return;
    visited[cur] = 1;
    dist[cur] = dep;
    sz++;
    for(auto nei: g[cur]){
        if(cur == 0) sz = 0;
        dfs(nei, dep+1);
        if(cur == 0) {paths[g_i] = new Node(0, sz); g_i++;}
        else {group[cur] = g_i;}
    }
}


void solve(){
    int n, q; cin >> n >> q;
    g.resize(n);
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dist.resize(n, 0);
    add.resize(n, 0);
    visited.resize(n, 0);
    paths.resize(g[0].size());
    group.resize(n, 0);
    dfs(0, 0);

    Node* dist_sg = new Node(0, n);

    for(int i=1; i<n; i++){
        paths[group[i]]->update(dist[i], dist[i]+1, a[i]);
    }

    for(int i=0; i<q; i++){
        int op; cin >> op;
        if(op == 1){
            int v, x, d; cin >> v >> x >> d; v--;
            if(dist[v] - d > 0){
                paths[group[v]]->update(dist[v]-d, dist[v]+d+1, x);
            }
            else{
                //add[d-dist[v]] += x;
                dist_sg->update(0, d-dist[v]+1, x);
                paths[group[v]]->update(d+1, dist[v]+d+1,x);
            }
        }
        else{
            int v; cin >> v; v--;
            if(v == 0) cout << a[0] + dist_sg->query(0, n) << endl;
            cout << paths[group[v]]->queryI(v) + dist_sg->query(dist[v], n) << endl;;
        }
    }

    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}