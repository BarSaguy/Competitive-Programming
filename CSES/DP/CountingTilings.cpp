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

// dp[level][mask]
vvi dp;
int n, m; // n<10 m<1000


int is_set(int mask, int pos){
    if(mask & (1 << pos)) return 1;
    return 0;
}

int set_mask(int mask, int pos){
    return mask | (1 << pos);
}

void f(int i, int j, int mask, int next_mask){
    if(i==m) return;
    if(j >= n){
        dp[i+1][next_mask] = (dp[i+1][next_mask] + dp[i][mask]) % MOD;
        return;
    }

    int my_mask = 1 << j;
    if(is_set(mask, j)){
        f(i, j+1, mask, next_mask);
        return;
    }
    f(i, j+1, mask, set_mask(next_mask, j));
    if(j+1 < n && !is_set(mask, j+1))
        f(i, j+2, mask, next_mask);
}


void solve(){
    cin >> n >> m;
    dp.resize(m+1, vi(1 << n));
    dp[0][0] = 1;
    rep(m){
        rep(mask, 0, 1<<n){
            f(i, 0, mask, 0);
        }
    }

    cout << dp[m][0] << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}