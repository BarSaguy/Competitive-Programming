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

vvi dp;

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vi p(n);
    for(int i=0; i<n; i++) cin >> p[i];
    dp.resize(n);
    for(int i=0; i<n; i++) dp[i].resize(k+1, 0);
    int s = 0;
    for(int i=0; i<n; i++){
        s += p[i];
        if(i-m >= 0) s-= p[i-m];
        for(int j=1; j<=k; j++){
            if(j <= (i+1)/m){
                if(i-m < 0 ) dp[i][j] = s;
                else dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + s);
            }
        }
    }
    cout << dp[n-1][k] << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}