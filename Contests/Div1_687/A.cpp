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
string a;
vi dp;
int n, p, k;
int x, y;
int f(int i){
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    dp[i] = (a[i]-'0')?0:x;
    dp[i] += f(i+k);
    return dp[i];
}

void solve(){
    cin >> n >> p >> k;
    a.clear();
    cin >> a;
    cin >> x >> y;
    dp.clear();
    dp.resize(n+1, -1);
    int ans = INF;
    int e=0;
    int c=0;
    p--;
    rep(i, p, n){
        int c = 0;
        c = (i-p)*y;
        //if(a[i] == '0') c -= x;
        int r = f(i);
        if(ans > r+c) ans = r+c;
    }
    if(ans == INF) ans = 0;
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}