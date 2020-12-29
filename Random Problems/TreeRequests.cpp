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
#define all(arr) (arr.begin(), arr.end())
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
const int LOG = 20;

vvi g;
vi visited;

vvi b;
string a;

void dfs(){

}

void solve(){
    // int n,m; cin >> n >> m; 
    // g.resize(n);

    // rep(n-1){
    //     int p; cin >> p; p--;
    //     //g[i+1].push_back(p);
    //     g[p].push_back(i+1);
    // }
    // cin >> a;W

    // b.resize(n);
    // rep(n) b[i].resize(LOG, -1);
    // visited.resize(n, 0);
    // vi leaves;
    // rep(n) if(g[i].empty()) leaves.push_back(i);
    // rep(leaves.size()) dfs(leaves[i]);
    
    // rep(m){

    // }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}