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

void solve(){
    int n, k; cin >> n >> k;
    vi h(n);
    rep(n) cin >> h[i];
    int low = h[0], high = h[0]+k;
    rep(i, 1, n){
        if(h[i] >= high){
            cout << "NO" << endl;
            return;
        }
        if(low >= h[i] + k + k-1){
            cout << "NO" << endl;
            return;
        }
        high = min(h[i]+k-1+k, high+(k-1));
        low = max(h[i], low-(k-1));
    }
    if(low == h[n-1])
        cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}