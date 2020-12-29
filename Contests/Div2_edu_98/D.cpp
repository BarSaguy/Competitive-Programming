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
const int MOD = 998244353;


int pow(int a, int p){
    if(p == 0) return 1;
    if(p == 1) return a;
    int r = pow(a, p/2);
    int ans = r * r % MOD;
    if(p%2)
        ans  = ans * a % MOD;
    return ans;
}

int inv(int n){
    return pow(n, MOD-2);
}


vi dp;

int inv2 = inv(2);
int inv4 = inv(4);

int d(int n){
    if(dp[n]) return dp[n];
    for(int i=3; i<=n; i++){
        dp[i] = (((dp[i-2]*inv4) % MOD) + ((dp[i-1]*inv2) % MOD))%MOD;
    }
    return dp[n];
}

void solve(){
    int n; cin >> n;
    dp.resize(n+1,0);
    dp[1] = inv(2);
    dp[0] = 1;
    dp[2] = inv(4);
    cout << d(n) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}