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


void solve(){
    int n, m; cin >> n >> m;
    DSU d;
    d.init(n);
    for(int i=0; i<m; i++){
        string q; cin >> q;
        int u, v; cin >> u >> v; u--;v--;
        if(q == "union"){
            d.uni(u, v);
        }
        else{
            if(d.find(u) == d.find(v))
                cout << "YES" << endl;
            else
            {
                cout << "NO" << endl;
            }
            
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