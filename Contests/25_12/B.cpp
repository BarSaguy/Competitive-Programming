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
const int MOD = 998244353;

int pow(int a, int p){
    if(p == 0) return 1;
    if(p == 1) return a;
    int r = pow(a, p/2);
    int ans = r * r % MOD;
    if(p%2)
        ans  = ans * a % MOD;
    return ans;
}

int inv(int n){
    return pow(n, MOD-2);
}

vi fact;

int factorial(int n){
    if(n <= 1) return 1;
    if(!fact[n])
        fact[n] = (n*factorial(n-1)) % MOD;
    return fact[n];
}

int choose(int n, int k){
    return ((factorial(n) * inv(factorial(n-k))) % MOD * inv(factorial(k))) % MOD;
}

int options(int a, int b, int i){
    return ((choose(a, i) * choose(b, i)) % MOD * factorial(i)) % MOD;
}

void solve(){
    int a,b,c; cin >> a >> b >> c;
    fact.resize(5001, 0);
    int ans1 = 1;
    for(int i=1; i<=min(a, b); i++){
        ans1 = (ans1 + options(a, b, i)) % MOD;
    }
    int ans2 = 1;
    for(int i=1; i<=min(a, c); i++){
        ans2 = (ans2 + options(a, c, i)) % MOD;
    }
    int ans3 = 1;
    for(int i=1; i<=min(c, b); i++){
        ans3 = (ans3 + options(c, b, i)) % MOD;
    }
    cout << ((ans1 * ans2) % MOD * ans3) % MOD;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}