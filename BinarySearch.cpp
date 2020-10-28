#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
vi a;
bool find(int c){
    int l=0, r=a.size(), m;
    while(l<r){
        m=(l+r)/2;
        if(a[m]==c) return true;
        else if(a[m] < c) l = m+1;
        else r = m;
    }
    return false;
}

void solve(){
    int n, k; cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<k; i++){
        int c; cin >> c;
        if(find(c))
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
        
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}