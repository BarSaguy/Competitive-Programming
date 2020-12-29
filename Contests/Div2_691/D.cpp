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


void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];
    int b_sum = 0;
    for(int i=0; i<n; i++){
        b_sum += b[i];
    }
    for(int i=0; i<n; i++){
        int ans = 0;
        int cur = 0;
        int cap = 0;
        for(int j=0; j<i+1; j++){
            cur += b[j];
            cap += a[j];
        }
        ans = cur + (b_sum-cur);
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}