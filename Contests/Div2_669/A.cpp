#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    vi a(n);
    int cnt = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] == 1)
            cnt++;
    }
    if(cnt <= n/2){
        cout << n-cnt << endl;
        for(int i=0; i<n-cnt; i++){
            if(i == cnt - 1)
                cout << 0 << endl;
            else
                cout << 0 << " ";
        }
    }
    else{
        
        cout << cnt-cnt%2 << endl;
        for(int i=0; i<cnt-cnt%2; i++){
            if(i == cnt - 1)
                cout << 1 << endl;
            else
                cout << 1 << " ";
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}