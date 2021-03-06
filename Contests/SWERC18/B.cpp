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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)

const int INF = 1e18;

vi a;
vi b;
int n;

int check(int m){
    // cout << "m: " << m << endl;
    m--;
    rep(n){
        if(i + m >= n) break;
        if(b[i]-a[i] >= m && a[i+m] <= a[i] && b[i+m] - a[i] >= m)
            return 1;
    }
    repr(i, n, 0){
        if(i - m < 0) break;
        if(b[i]-a[i] >= m && a[i-m] <= a[i] && b[i-m] - a[i] >= m)
            return 1;
    }
    rep(n){
        if(i + m >= n) break;
        if(b[i]-a[i] >= m && b[i+m] >= b[i] && b[i] - a[i+m] >= m)
            return 1;
    }
    repr(i, n, 0){
        if(i - m < 0) break;
        if(b[i]-a[i] >= m && b[i-m] >= b[i] && b[i] - a[i-m] >= m)
            return 1;
    }
    return 0;
}

void solve(){
   cin >> n;
    a.resize(n, INF);
    b.resize(n, -1);
    rep(n){
        cin >> a[i] >> b[i];
    }
    int l=1, r=n+1;
    int ans = 1;
    while(l < r){
        int m = (l+r)/2;
        if(check(m)){
            l = m+1;
            ans = m;
        } else{
           r = m; 
        }
    }

    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}