#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

int mxN = (int)10e18;

void solve(){
    int n; cin >> n;
    char op;
    vi a(n, -1);
    vi r(n);
    vi cnt(n, 0);
    int idx = 0;
    bool result = true;
    for(int i=0; i<2*n; i++){
        cin >> op;
        if(op == '-'){
            int c; cin >> c;
            if(result){
                idx--;
                if(idx < 0 || c < a[idx]){
                    result = false;
                }
                else{
                    r[cnt[idx]] = c;
                    if(idx == 0)
                        cnt[idx]++;
                    if(idx > 0)
                        a[idx-1] = max(a[idx-1], c);
                    a[idx] = -1;
                }
            }
        }
        else
        {
            if(idx > 0){
                cnt[idx] = cnt[idx] + cnt[idx-1]+1;
            }
            idx++;
        }
    }
    if(result){
        cout << "YES" << endl;
        for(int i=0; i<n; i++){
            if(i == n-1)
                cout << r[i] << endl;
            else
                cout << r[i] << " ";
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t = 1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}