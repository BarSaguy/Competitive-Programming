#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>

const int INF = 1e18;

struct SEG{
    vi a;
    vi pre;
    vi suf;
    int sz;

    SEG(int n){
        for(sz=1; sz<n;sz*=2);
        a.resize(2*sz, 0);
        pre.resize(2*sz, 0);
        suf.resize(2*sz, 0);
    }

    void set(int i, int x){
        i += sz;
        a[i] = x;
        for(i/=2;i;i/=2){
            a[i] = min(a[2*i],a[2*i+1]);  
        }
    }
    int query(int l, int r){
        int res = INF;
        for(l+=sz, r+=sz; l <= r; l/=2, r/=2){
            if(l%2==1) res = min(res,a[l++]);
            if(r%2==0) res = min(res,a[r--]);
        }
        return res;
    }
};


int32_t main()
{
    ios_base::sync_with_stdio(false);

    int n,m; cin >> n >> m;
    vi b(n); 
    SEG s(n); 
    for(int i=0; i<n; i++){
        cin >> b[i];
        s.set(i, b[i]);
    }

    for(int i=0; i<m; i++){
        int q, a, b; cin >> q >> a >> b;
        if(q == 1){
            s.set(a, b);
        }
        else
        {
            cout << s.query(a,b-1) << endl;
        }
        
    }


    return 0;
}