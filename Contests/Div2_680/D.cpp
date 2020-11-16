#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

const int MOD = 998244353;

vi f;

int pow(int n, int p){
    if(p==1)
        return n;
    int c = pow(n, p/2);
    int ans = (c*c) % MOD;
    if(p%2)
        ans = (ans * n) % MOD;
    return ans;
}

int fact(int n){
    int r = 1;
    for(int i=2; i<=n; i++){
        r *= i;
        r = r % MOD;
    }
    return r;
}

int choose(int a, int b){
    int f = pow(fact(b), MOD-2);
    return fact(a) *f%MOD*f%MOD;
}

void solve(){
    int n; cin >> n;
    int sz = 2*n;
    vi a(sz);
    for(int i=0; i<sz; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    int c = choose(2*n, n);
    for(int i=0; i<sz; i++){
        if(i >= n)
            ans = (ans + (a[i] * c)%MOD) % MOD;
        else{
            ans = (ans + (MOD - (a[i] * c)%MOD)) % MOD;
        }
    }

    cout << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}