#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    for(int i=2*n; i<4*n; i+=2){
        if(i == 4*n-2)
            cout << i << endl;
        else
        {
            cout << i << " ";
        }
        
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}