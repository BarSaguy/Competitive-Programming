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

vi ans;

void ntb(int n){
    n /= 4;
    bool first = true;
    while(n > 0){
        if(first){
            ans.push_back(1); first = false;}
        else
        {
            ans.push_back(0);
        }
        
        n /= 2;
    }
    ans.push_back(1);
}


void solve(){
    int k; cin >> k;
    ans.clear();
    if(k%2 == 1){
        cout << -1 << endl;
        return;
    }
    int i = 1;
    while(k > 0){
        if(k%2)
            ntb(i);
        i*=2;
        k /= 2;
    }
    int sz = ans.size();
    cout << sz << endl;
    for(int i=0; i< sz; i++){
        cout << ans[i] << " ";
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