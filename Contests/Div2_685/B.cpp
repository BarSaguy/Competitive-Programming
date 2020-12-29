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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vi o1(n+2, 0),z1(n+2, 0), o2(n+2, 0),z2(n+2, 0);
    int f1 = 0, f2 = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0' || f1){
            z1[i+1] = 1;
            f1 = 1;
        }
        if(s[i] == '1' || f2){
            o1[i+1] = 1;
            f2= 1;
        }
    }
    f1 = 0; f2 = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i] == '0' || f1){
            z2[i+1] = 1;
            f1 = 1;
        }
        if(s[i] == '1' || f2){
            o2[i+1] = 1;
            f2= 1;
        }
    }

    for(int i=0; i<q; i++){
        int l, r; cin >> l >> r;
        if(s[l-1] == '1'){
            if(o1[l-1] == 1){
                cout << "YES" << endl;
                continue;
            }
        }
        else{
            if(z1[l-1] == 1){
                cout << "YES" << endl;
                continue;
            }
        }
        if(s[r-1] == '1'){
            if(o2[r+1] == 1){
                cout << "YES" << endl;
                continue;
            }
        }
        else{
            if(z2[r+1] == 1){
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}