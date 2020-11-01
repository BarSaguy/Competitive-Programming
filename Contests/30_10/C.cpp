#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    vi c;
    c.resize(20, 0);
    for(int i=0; i<n; i++){
        int t = a[i];
        for(int j=0; j<20; j++){
            c[j] += t%2;
            t/=2;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int n1 = 0;
        for(int j=19; j>=0; j--){
            n1 *= 2;
            if(c[j]){
                c[j]--;
                n1 += 1;
            }
        }
        ans += n1*n1;
    }

    cout << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}