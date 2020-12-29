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

vi b;
vi l;

void solve(){
    int n, m; cin >> n >> m;
    b.clear();
    l.clear();
    b.resize(100, 0);
    l.resize(100, 0);
    int t;
    for(int i=0; i<n; i++){ cin >> t; b[t-1] = 1;}
    for(int i=0; i<m; i++){cin >> t; l[t-1] = 1;}
    int ans = 0;
    for(int i=0; i<100; i++){
        if(b[i] == 1 && l[i] == 1)
            ans++;
    }
    cout << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}