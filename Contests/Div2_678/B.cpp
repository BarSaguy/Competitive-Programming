#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>



void solve(){
    int n; cin >> n;
    int s, e;
    vvi a;
    if(n%2 == 0){
        s = n/2-1;
        e = n/2+1;
    }
    else
    {
        s = n/2-1;
        e = n/2+2;
    }
    if(s < 0)
        s = 0;
    if(e > n)
        e = n;
    
    a.resize(n);
    for(int i=0; i<n; i++)
        a[i].resize(n, 0);
    for(int i=0; i<n; i++){
        a[i][i] = 1;
        a[i][n-1-i] = 1;
        a[n-1-i][i] = 1;
        a[n-1-i][n-1-i] = 1;
    }
    for(int i=s; i<e; i++){
        for(int j=s; j<e; j++)
            a[i][j] = 1;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}