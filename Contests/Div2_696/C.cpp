#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define pqii priority_queue<ii>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, s, n) for (int i = (s); i < (n); i++)
#define repr(...) GET_MACRO(__VA_ARGS__, repr3, repr2, repr1)(__VA_ARGS__)
#define repr1(n) for (int i = (n)-1; i >= 0; i--)
#define repr2(i, n) for (int i = (n)-1; i >= 0; i--)
#define repr3(i, n, s) for (int i = (n)-1; i >= (s); i--)
#define pb push_back
#define eb emplace_back

const int INF = 1e18;



void solve(){
    int n;
    vii ans;
    vi a;
    cin >> n;
    int sz = 2*n;
    a.resize(sz); rep(sz) {cin >> a[i];}
    sort(all(a));
    int found=0;
    vi used(sz, 0);
    int x = a[sz-1];
    int skip=0;
    rep(sz-1){
        int x = a[sz-1];
        multiset<int> s;
        rep(j, sz-1){
            if(i==j)continue;
            s.insert(a[j]);
        }
        found=0;
        ans.clear();
        repr(j, sz-1){
            if(ans.size() == n-1) {found=1;break;}
            if(j == i) continue;
            auto it = s.find(a[j]);
            if(it == s.end()) continue;
            s.erase(it);
            it = s.find(x-a[j]);
            if(it == s.end())continue;
            ans.pb({a[j], *it});
            s.erase(it);
            x = a[j];
        }
        if(found){
            cout << "YES" << endl;
            cout << a[i] + a[sz-1] << endl; cout << a[i] << " " << a[sz-1] << endl;
            rep(ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
            int idx=0;
            return;
        }
    }
    cout << "NO" << endl;    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}