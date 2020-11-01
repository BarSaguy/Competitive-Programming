#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

const int INF = 1e18;

struct SEG{
    vi a;
    int sz;

    SEG(int n){
        for(sz=1; sz<n;sz*=2);
        a.resize(2*sz, 0);
    }

    void set(int i){
        i += sz;
        a[i] = !a[i];
        for(i/=2;i;i/=2) a[i] = a[2*i] + a[2*i+1];
    }
    int query(int k){
        int i = 1;
        k++;
        while(i < 2*sz){
            if(i >= sz) return i-sz;
            if(a[2*i] >= k){
                i = 2*i;
            }
            else{
                k -= a[2*i];
                i = 2*i+1;
            }
        }
        return -1;
    }
};


void solve(){
    int n, m; cin >> n >> m;
    int a;
    SEG s(n);
    for(int i=0; i<n; i++){
        cin >> a;
        if(a)
            s.set(i);
    }

    for(int i=0; i<m; i++){
        int op; cin >> op;
        if(op == 1){
            int idx; cin >> idx; s.set(idx);
        }
        else{
            int k; cin >> k; cout << s.query(k) << endl;
        }
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}