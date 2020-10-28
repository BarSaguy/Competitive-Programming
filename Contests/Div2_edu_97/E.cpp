#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vi a;
vi b;

const int INF = 1e18+2;

int lis(int s, int e){
    int n = e-s+1;
    vi d(n+1, INF);
    d[0] = -INF;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[s+i]) - d.begin();
        if(j == 1 && i != 0)
            continue;
        if (d[j-1] <= a[s+i] && a[s+i] < d[j]){
            d[j] = a[s+i];
            ans = j;
        }
    }

    // int ans = 0;
    // for (int i = 0; i <= n; i++) {
    //    if (d[i] < INF)
    //        ans = i;
    //}
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    a.resize(n+2);
    a[0] = -INF+1;
    a[n+1] = INF-1;
    for(int i=0; i<n; i++){
        cin >> a[i+1];
        a[i+1] = a[i+1] - i;
    }
    b.resize(k+2);
    b[0] = 0; b[k+1] = n+1;
    for(int i=0; i<k; i++){
        cin >> b[i+1];
        if(a[b[i+1]] - a[b[i]] < 0){
            cout << -1 << endl;
            return;
        }
    }
    int sum = 0;
    for(int i=0; i<k+1; i++){
        int ans = lis(b[i], b[i+1]);
        sum += b[i+1] - b[i] + 1 - ans;
    }
    cout << sum << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t = 1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}