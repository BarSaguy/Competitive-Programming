#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void query(int x, int y){
    x++;y++;
    cout << "? " << x << " " << y << endl;
}

void solve(){
    int n; cin >> n;
    int idx = 0, ans, a2, a1;
    vi r(n);
    for(int i=1; i<n; i++){
        query(idx, i);
        cin >> a1;
        query(i, idx);
        cin >> a2;
        if(a2 > a1){
            r[i] = a2;
        }
        else{
            r[idx] = a1;
            idx = i;
        }
    }
    r[idx] = n;

    cout << "! ";
    for(int i=0; i<n; i++){
        if(i==n-1)
            cout << r[i] << endl;
        else
            cout << r[i] << " ";
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}