#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

const int INF = 1e9;

void solve(){
    int n; cin >> n;
    vi a(n);
    vi b(n);
    int s = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i > 0){
            b[i] = a[i] - a[i-1];
        }
        else
        {
            b[i] = a[i];
        }
        s += min(0LL, b[i]);
    }
    if(s + a[0] >= 0) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}