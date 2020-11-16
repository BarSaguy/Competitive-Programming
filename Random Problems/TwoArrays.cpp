#include <bits/stdc++.h>

using namespace std;
#define int long long
#define vi vector<int>


void solve(){
    int n, T; cin >> n >> T;
    int a;
    bool side = false;
    for(int i=0; i<n; i++){
        cin >> a;
        if(T - a < T/2 || (T - a == T/2 && T%2==1) )
            cout << "0 ";
        else if(T-a == T/2){
            cout << side << " ";
            side = !side;
        }
        else
            cout << "1 ";
    }
    cout << endl;

}


int32_t main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }

    return 0;
}