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
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    vi c1(26, 0), c2(26, 0);
    int s = 0;
    for(int i=0; i<n; i++){
        c1[a[i]-'a']++;
        c2[b[i]-'a']++;
    }
    for(int i=0; i<26; i++){
        if(c1[i] % k != c2[i] % k){
            cout << "No" << endl;
            return;
        }
        s += c1[i] - c2[i];
        if(s < 0){
            cout << "No" << endl; return;
        }
    }
    cout << "Yes" << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}