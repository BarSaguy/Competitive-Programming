#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int l, r; cin >> l >> r;
    if(r < 2*l){
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}