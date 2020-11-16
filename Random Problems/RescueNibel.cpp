#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

int mod = 998244353;
vi c;

void solve(){
    int n, k; cin >> n >> k;
    c.resize(n+1);
    c[k] = k;
    for(int i=k+1; i<n; i++){
        c[i] = (c[i-1] * i  / (i-k+1)) % mod;
    }
    multiset<pair<double, int>> m;
    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;
        m.insert({l+0.0, 0LL});
        m.insert({r+0.5, 1LL});
    }
    int count = 0;
    int sum = 0;
    for(auto iter: m){
        if(iter.second == 0LL){
            count++;
            if(count > k){
                sum += c[count-1] % mod;
                sum = sum % mod;
            }
            else if(count == k){
                sum += 1;
                sum = sum % mod;
            }    
        }
        else
            count--;
    }

    cout << sum << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    //int t; cin >> t;
    int t = 1;
    for(int i=0; i<t; i++) solve();
    return 0;
}