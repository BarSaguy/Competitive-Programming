#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vi a;
vi b;

const int INF = 1e18+1;

int dp(int s, int e, int min_val, int max_val){
    int ans = e-s;
    for(int i=s; i<e-1; i++){
        if(a[i] > a[i+1]){
            ans = min(ans, dp(s, i, min_val, a[i]) + dp(i, e, a[i], max_val));
        }
    }
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int c;
    for(int i=0; i<k; i++){
        cin >> c;
        b.push_back(c);
    }
    int ans;
    if(k==0){
        ans = dp(0, n, -INF, INF);
        cout << ans << endl;
    }
    else{
        ans = dp(0, b[0], -INF,a[b[0]]);
        int sum = ans;
        if(ans == -1){
            cout << -1 << endl;
            return;
        }
        for(int i=1; i<k; i++){
            ans = dp(b[i-1]+1, b[i], a[b[i-1]],a[b[i]]);
            if(ans == -1){
                cout << -1 << endl;
                return;
            }
            sum += ans;
        }
        ans = dp(b[k-1]+1, n, a[b[k-1]], INF);
        if(ans == -1){
            cout << -1 << endl;
            return;
        }
        sum += ans;
        cout << sum << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t = 1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}