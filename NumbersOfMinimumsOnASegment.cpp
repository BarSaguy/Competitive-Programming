#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>

const int INF = 1e18;

struct SEG{
    vi a;
    vi c;
    int sz;

    SEG(int n){
        for(sz=1; sz<n;sz*=2);
        a.resize(2*sz, INF);
        c.resize(2*sz, 0);
    }

    void set(int i, int x){
        i += sz;
        a[i] = x;
        c[i] = 1;
        for(i/=2;i;i/=2){
            a[i] = min(a[2*i],a[2*i+1]);
            if(a[2*i] == a[2*i+1])
                c[i] = c[2*i] + c[2*i+1];
            else c[i] = a[2*i] < a[2*i+1] ? c[2*i]:c[2*i+1];
            
        }
    }
    pair<int, int> query(int l, int r){
        int res = INF;
        int cnt = 0;
        for(l+=sz, r+=sz; l <= r; l/=2, r/=2){
            if(l%2==1) {
                if(res > a[l])
                    cnt = c[l];
                else if(res == a[l])
                    cnt += c[l];
                res = min(res,a[l++]);
            }
            if(r%2==0) {
                if(res > a[r])
                    cnt = c[r];
                else if(res == a[r])
                    cnt += c[r];
                res = min(res,a[r--]);
            }
        }
        return {res,cnt};
    }
};


int32_t main()
{
    ios_base::sync_with_stdio(false);

    int n,m; cin >> n >> m;
    int b;
    SEG s(n); 
    for(int i=0; i<n; i++){
        cin >> b;
        s.set(i, b);
    }

    for(int i=0; i<m; i++){
        int q, a, b; cin >> q >> a >> b;
        if(q == 1){
            s.set(a, b);
        }
        else
        {
            pair<int,int> ans = s.query(a,b-1);
            cout << ans.first << " " << ans.second << endl;
        }
        
    }


    return 0;
}