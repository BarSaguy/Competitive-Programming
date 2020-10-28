#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int  ans = 0;
    if(n > 1) ans = 1;
    int c_cnt = 1, b_cnt = 0, n_cnt = 1;
    for(int i=2; i<n; i++){
        if((a[i] < a[i-1])){
            b_cnt++;
            if(b_cnt >= c_cnt){
                c_cnt = n_cnt;
                b_cnt = 0;
                n_cnt = 1;
                ans++;
            }
            else n_cnt++;
        }
        else{
            n_cnt++;
        }
    }

    cout << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}