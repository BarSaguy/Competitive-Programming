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
#define eb emplace_back

const int INF = 1e18;
const int MOD = 1e9+7;

int pow(int a, int p){
    if(p == 0) return 1;
    int r = pow(a, p/2);
    int ans = r * r % MOD;
    if(p%2)
        ans  = ans * a % MOD;
    return ans;
}

int inv(int n){
    return pow(n, MOD-2);
}


vvi dp;
int n;

int f(int i, int sum){
    if(sum == 0) return 1;
    if(i > n || sum < 0) return 0;
    if(dp[i][sum] != -1) return dp[i][sum];
    dp[i][sum] = (f(i+1, sum-i) + f(i+1, sum)) % MOD;
    return dp[i][sum];
}

void solve(){
    cin >> n;
    int sum = n*(n+1) / 4;
    dp.resize(n+1);
    rep(n+1) dp[i].resize(sum+1, -1);
    if(n*(n+1) % 4 != 0){
        cout << "0" << endl;
        return;
    }
    cout << f(1, sum)*inv(2)%MOD << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}