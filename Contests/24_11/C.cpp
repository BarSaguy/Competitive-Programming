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
// const int MOD = 998244353;

// int pow(int a, int p){
//     if(p == 0) return 1;
//     if(p == 1) return a;
//     int r = pow(a, p/2);
//     int ans = r * r % MOD;
//     if(p%2)
//         ans  = ans * a % MOD;
//     return ans;
// }

// int inv(int n){
//     return pow(n, MOD-2);
// }


vvi g;
vi d;
vi visited;
vvi lca;
int n; 

void calc_depth(int c, int depth){
    if(visited[c]) return;
    visited[c] = 1;
    d[c] = depth;
    for(auto nei: g[c]){
        calc_depth(nei, depth+1);
    }
}

void calc_blift(int c){
    visited[c] = 1;
    for(auto nei: g[c]){
        if(!visited[nei]){
            lca[nei][0] = c;
            int i = 0;
            while(lca[nei][i] != -1){
                lca[nei][i+1] = lca[lca[nei][i]][i];
                i++;
            }
            calc_blift(nei);
        }
    }
}

int anc(int c, int l){
    for(int i=0; l != 0; i++){
        if(l % 2 == 1){
            c = lca[c][i];
        }
        l /= 2;
    }
    return c;
}

int find_lca(int a, int b){
    if(d[a] > d[b]) swap(a,b);
    b = anc(b, d[b] - d[a]);
    if(a == b) return a;
    for(int i=32; i>=0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}

void solve(){
    cin >> n;
    g.resize(n);
    d.resize(n, 0);
    lca.resize(n);
    for(int i=0; i<n; i++)lca[i].resize(33, -1);
    visited.resize(n, 0);
    for(int i=0; i<n-1; i++){
        int u,v; cin >> u >> v; u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc_depth(0, 0);
    for(int i=0; i<n; i++)visited[i] = 0;
    calc_blift(0);
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int a,b,c; cin >> a >> b>> c;
        a--; b--;
        int l = find_lca(a, b);
        if(d[b] + d[a] - d[l] <= c){
            cout << b+1 << endl;
        }
        else if(d[a] - d[l] >= c){
            cout << anc(a, c)+1 << endl;
        }
        else{
            c = c - (d[a] - d[l]);
            cout << anc(b, d[b] - d[l] - c)+1 << endl;
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