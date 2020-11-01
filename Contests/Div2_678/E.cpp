#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vi a;
vvi b;

struct SEG{

};

void solve(){
    int n; cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    b.resize(n);
    for(int i=0; i<n; i++){
        b[i].push_back(-1);
    }
    for(int i=0; i<n; i++){
        b[a[i]-1].push_back(i);
    }
    for(int i=0; i<n; i++){
        b[i].push_back(n);
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t = 1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}