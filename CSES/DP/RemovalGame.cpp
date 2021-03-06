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

vi a;

vvi dp1;
vvi dp2;

int f2(int l, int r);

int f1(int l, int r){
    if(l > r) return 0;
    if(l == r) return a[l];
    if(dp1[l][r] != INF) return dp1[l][r];
    dp1[l][r] = max(f2(l+1, r) + a[l], f2(l, r-1) + a[r]);
    return dp1[l][r];
}

int f2(int l, int r){
    if(l >= r) return 0;
    if(dp2[l][r] != INF) return dp2[l][r];
    dp2[l][r] = min(f1(l+1, r), f1(l, r-1));
    return dp2[l][r];
}

void solve(){
    int n; cin >> n;
    a.resize(n);
    rep(n) cin >> a[i];
    dp1.resize(n);
    rep(n) dp1[i].resize(n, INF);
    dp2.resize(n);
    rep(n) dp2[i].resize(n, INF);

    cout << f1(0, n-1) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}