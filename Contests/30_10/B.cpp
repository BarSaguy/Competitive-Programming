#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vi preva(n);
    vi prevb(n);
    vi tmpa(n);
    vi tmpb(n);
    for(int i=0; i<n; i++){
        preva[i] = 1;
        prevb[i] = 1;
    }

    for(int j=1; j<m; j++){
        for(int i=0; i<n; i++){
            tmpa[i] = preva[i];
            tmpb[i] = prevb[i];
        }
        for(int i=0; i<n; i++){
            for(int k=0; k<i; k++){
                preva[i] += tmpa[k] % MOD;
                preva[i] %= MOD;
            }

            for(int k=n-1; k>=i+1; k--){
                prevb[i] += tmpb[k] % MOD;
                prevb[i] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=i; j--){
            ans += (prevb[j] * preva[i]) % MOD;
            ans %= MOD;
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