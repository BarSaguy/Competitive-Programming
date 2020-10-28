#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    vi a(n);
    vi b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(),greater<int>());
    for(int i=0; i<n; i++){
        b[i] = a[i];
    }
    int prev_gcd = b[0];
    for(int i=1; i<n-1; i++){
        int max_gcd=0, idx;
        for(int j=i; j<n; j++){
            int g = __gcd(prev_gcd, b[j]);
            if(g > max_gcd){
                max_gcd = g;
                idx = j;
            }
        }
        prev_gcd = max_gcd;
        int t = b[i];
        b[i] = b[idx];
        b[idx] = t;
    }

    for(int i=0; i<n; i++){
        cout << b[i] << " \n"[i==n-1?1:0];
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}