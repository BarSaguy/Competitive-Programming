#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
vvi g;
vi a;
vi l;
vi t;

int calc_l(int start){
    int ans = 0;
    if(g[start].empty())
        ans = 1;
    for(int nei: g[start]){
        ans += calc_l(nei);
    }
    l[start] = ans;
    return l[start];
}

int calc_t(int start){
    int ans = 0;
    for(int nei: g[start]){
        ans += calc_t(nei);
    }
    t[start] = ans + a[start];
    return t[start];
}

int rec(int start){
    int ans = 0;
    for(int nei: g[start]){
        ans = max(rec(nei), ans);
    }
    int add;
    if(t[start] % l[start] != 0)
        add = t[start]/l[start] + 1;
    else
    {
        add = t[start]/l[start];
    }
    
    ans = max(ans, add);
    return ans;
}

void solve(){
    int n; cin >> n;
    g.resize(n);
    g.clear();
    a.resize(n);
    l.resize(n);
    t.resize(n);

    for(int i=0; i<n-1; i++){
        int p; cin >> p;
        g[p-1].push_back(i+1);
    }
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    calc_l(0);
    calc_t(0);
    cout << rec(0) << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t = 1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}