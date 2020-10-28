#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

int mxN = 1e18;

void solve(){
    int w, h, n; cin >> w >> h >> n;
    int ans;
    int l=0, r=mxN+1, m;
    while(l<r){
        m = (l+r)/2;
        if(m/w >= 1e9 && m/h > 0) ans=m, r=m;
        else if (m/h >= 1e9 && m/w > 1) ans = m, r=m;
        else if((m/w) * (m/h) >= n) ans=m, r=m;
        else l = m+1;
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}