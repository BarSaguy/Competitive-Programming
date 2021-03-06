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

const int INF = 1e18;

vector<vector<double>> dp;

double f(int n, int k){
    if(n == 0 || k == 0) return 0;
    if(n == 1) return 0.5;
    if(dp[n][k] != -1) return dp[n][k];
    dp[n][k] = 0.5*(f(n-1, k-1)+1+f(n, k-1)); 
    return dp[n][k];
}

void solve(){
    int n, k; cin >> n >> k;
    double ans = 0;
    
    dp.resize(n+1);
    rep(n+1) dp[i].resize(k+1, -1);
    cout << f(n, k) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cout<<fixed<<setprecision(10);
    //cin >> t;
    while(t--) solve();
    return 0;
}