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

const int INF = 1e18;
const int MOD = 1e9+7;

vvi g;
vi visited;
vi bits;

void dfs(int c){
    if(bits[c] == 1) return;
    bits[c] = 1;
    for(auto nei:g[c]) dfs(nei);
}

void solve(){
    int n,m; cin >> n >> m;
    bits.resize(m, 0);
    g.resize(m);
    vvi a(n);
    rep(n){
        int k; cin >> k;
        rep(j, k){int x; cin >> x;x--;a[i].push_back(x);}
    }
    int ans = 1;
    vi ans_set;
    rep(n){
        int u = a[i][0];
        if(a[i].size() == 1){
            if(bits[u] == 1) continue;
            if(bits[u] == 2) dfs(u);
            bits[u] = 1;
            ans = ans*2%MOD;
            ans_set.push_back(i);
        }
        else{
            int v = a[i][1];
            if((bits[u]==2 && bits[v]==2) || (bits[u] == 1 && bits[v] == 1)) continue;
            if(bits[u] == 0 && bits[v] == 0){
                bits[v] = 2;
                bits[u] = 2;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            else if(bits[u] == 1){
                dfs(v);
                bits[v] = 1;
            }
            else if(bits[v] == 1){
                dfs(u);
                bits[u] = 1;
            }
            else if(bits[u] == 2){
                bits[v] = 2;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            else if(bits[v] == 2){
                bits[u] = 2;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            ans = ans*2%MOD;
            ans_set.push_back(i);
        }
    }
    cout << ans << " " << ans_set.size() << endl;
    rep(ans_set.size()){
        cout << ans_set[i]+1 << " ";
    }
    cout << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}