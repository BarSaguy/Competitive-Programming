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

void solve(){
    int n; cin >> n;
    vi w(n);
    rep(n) cin >> w[i];
    vi deg(n, 0);
    pqi pq;
    int ans = 0;
    rep(n-1){
        int u, v; cin >> u >> v;
        u--;v--;
        deg[u]++;
        deg[v]++;
        if(deg[u] > 1){
            pq.push(w[u]);
        }
        if(deg[v] > 1){
            pq.push(w[v]);
        }
    }
    rep(n) ans += w[i];
    rep(n-1){
        cout << ans << " ";
        if(i < n-2){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}