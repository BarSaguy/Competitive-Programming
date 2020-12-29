#include <bits/stdc++.h>

using namespace std;

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

const int INF = 1 << 31;

vvi dp;
vi a;
int n, p, q;

int check(int w){
    rep(n+1) dp[i].assign(n+1, INF);
    vi old_move(n); old_move[0] = -1;
    vi young_move(n); young_move[0] = -1;
    vi d(n);
    d[0] = INF;
    sort(all(a));
    rep(n-1) d[i+1] = a[i+1]-a[i];
    int l=n-1, r=n-1, sum=0;
    while(r >= 1){
        while(sum < w && l >= 0){
            sum += d[l];
            l--;
        }
        young_move[r] = l;
        sum -= d[r];
        r--;
    }
    l=n-1; r=n-1; sum=0;
    while(r >= 1){
        while(sum < 2*w && l >= 0){
            sum += d[l];
            l--;
        }
        old_move[r] = l;
        sum -= d[r];
        r--;
    }
    int pos = n-1;
    rep(p){
        dp[i+1][0] = young_move[pos];
        pos = young_move[pos];
        if(pos == -1) return 1;
    }
    pos = n-1;
    rep(q){
        dp[0][i+1] = old_move[pos];
        pos = old_move[pos];
        if(pos == -1) return 1;
    }
    rep(i, 1, p+1){
        rep(j, 1, q+1){
            dp[i][j] = min(young_move[dp[i-1][j]], old_move[dp[i][j-1]]);
            if(dp[i][j] == -1) return 1;
        }
    }
    return 0;
}

int MinimumEffort(int N, int P, int Q, vi A){
    n=N; p = P; q = Q; a=A; 
    if(p + q >= n){
        return 1;
    }
    dp.resize(n+1);
    rep(n) dp[i].resize(n+1);
    int l=1, r=1e9+1;
    int ans = INF;
    while(l < r){
        int m = (l+r)/2;
        if(check(m)){
            ans = m;
            r = m;
        }
        else{
            l = m+1;
        }
    }
    return ans;
}

// void solve(){
//     int n, p, q;
//     cin >> n >> p >> q;
//     vi a;
//     a.resize(n);
//     rep(n) cin >> a[i];
//     cout << MinimumEffort(n, p, q, a) << endl;
// }

// int32_t main(){
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     int t=1;
//     //cin >> t;
//     while(t--) solve();
//     return 0;
// }