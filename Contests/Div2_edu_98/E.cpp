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

vi a;
vi s;
vvi b;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    a.resize(n, 0);
    b.resize(n);
    s.resize(n, 0);
    for(int i=0; i<n; i++) b[i].resize(n, 0);

    for(int i=0; i<m; ++i){
        int l, r; cin >> l >> r;
        l--;r--;
        for(int j=l; j<r+1; ++j){
            ++a[j];
            for(int j2=j; j2<r+1; ++j2){
                ++b[j2][j];
            }
        }
    }
    int c = 0;
    for(int i=0; i<n; i++){
        c += a[i];
        if(i >= k) c -= a[i-k];
        s[i] = c;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i] + s[j] - b[j][i] > ans)
                ans = s[i] + s[j] - b[j][i];
        }
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}