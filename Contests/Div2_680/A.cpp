#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n, x; cin >> n >> x;
    vi a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<n; i++){
        if(a[i] + b[n-i-1] > x){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}