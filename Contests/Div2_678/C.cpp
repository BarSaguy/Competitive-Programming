#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

int mod = 1e9 + 7;

int fact(int s, int e){
    int f = 1;
    for(int i=s; i<=e; i++)
        f = (f * i) % mod;
    return f;
}

void solve(){
    int x, n, pos; cin >> n >> x >> pos;
    int s=0, b=0, t = pos, t2 = n-1;
    int l = 0, e = n, m;
    while(l < e){
        m = (l + e) / 2;
        if(m < pos){
            s++;
            l = m + 1;
        }
        else if(m > pos){
            b++;
            e = m;
        }
        else l = m+1;
    }
    cout << ((fact(n-x-b+1, n-x) * fact(x-s, x-1))% mod * fact(1, n-b-s-1)) % mod << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}