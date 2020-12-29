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
    vector<string> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vi ans;
    for(int i=0; i<10; i++){
        int ans = 0;
        vi min_r(n, INF);
        vi max_r(n, -INF);
        vi min_c(n, INF);
        vi max_c(n, -INF);
        int m1_c=-INF, m2_c=INF, m1_r=-INF, m2_r=INF;
        for(int k=0; k<n; k++){
            for(int p=0; p<n; p++){
                if(a[k][p] == i + '0'){
                    if(max_r[p] < k) max_r[p] = k;
                    if(min_r[p] > k) min_r[p] = k;
                    if(min_c[k] > p) min_c[k] = p;
                    if(max_c[k] < p) max_c[k] = p;
                    if(m1_r < k) m1_r = k;
                    if(m2_r > k) m2_r = k;
                    if(m1_c < p) m1_c = p;
                    if(m2_c > p) m2_c = p;
                }
            }
        }

        for(int i=0;i<n; i++){
            if(max_r[i] != -INF){
                if((max_r[i] - min_r[i]) * max(n-i-1, i) > ans){
                    ans = max(ans, (max_r[i] - min_r[i]) * max(n-i-1, i));
                }
                if(max(n - max_r[i]-1, max_r[i]) * max(abs(m1_c - i), abs(i-m2_c)) > ans){
                    ans = max(ans, max(n - max_r[i]-1, max_r[i]) * max(abs(m1_c - i), abs(i-m2_c)));
                }
                if(max(n - min_r[i]-1, min_r[i]) * max(abs(m1_c - i), abs(i-m2_c)) > ans){
                    ans = max(ans, max(n - min_r[i]-1, min_r[i]) * max(abs(m1_c - i), abs(i-m2_c)));
                }
            }
            if(max_c[i] != -INF){
                if((max_c[i] - min_c[i]) * max(n-i-1, i) > ans){
                    ans = max(ans, (max_c[i] - min_c[i]) * max(n-i-1, i));
                }
                if(max(n - max_c[i]-1, max_c[i]) * max(abs(m1_r - i), abs(i-m2_r)) > ans){
                    ans = max(ans, max(n - max_c[i]-1, max_c[i]) * max(abs(m1_r - i), abs(i-m2_r)));
                }
                if(max(n - min_c[i]-1, min_c[i]) * max(abs(m1_r - i), abs(i-m2_r)) > ans){
                    ans = max(ans, max(n - min_c[i]-1, min_c[i]) * max(abs(m1_r - i), abs(i-m2_r)));
                }
            }
        }
        

        cout << ans << " ";

    }
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}