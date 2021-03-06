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
#define x first
#define y second
#define pb push_back
#define eb emplace_back

const int INF = 1e18;

void solve(){
    int n; cin >> n;
    vi r(n), l(n);
    rep(n) cin >> l[i] >> r[i];
    int m; cin >> m;
    vi p(m);
    rep(m) cin >> p[i];
    sort(all(r));
    sort(all(l));
    sort(all(p));
    int c = 0;
    vi cnt(n, 0);
    vi v(n, -1);
    vi ans;
    rep(m){
        while(c < n && r[c] < p[i]){
            c++;
        }
        if(c == n) break;
        if(l[c] <= p[i] && p[i] <= r[c]){
            cnt[c]++;
            v[c] = p[i];
            
            if(r[c] == p[i] && c < n-1){
                if(l[c+1] == r[c]){
                    cnt[c+1]++; v[c+1]=r[c];
                }
            }
        }
    }

    rep(n){
        if(cnt[i] > 2) {
            cout << "impossible" << endl;
            return;
        }
        if(cnt[i] == 2) continue;
        if(cnt[i] == 0){
            v[i] = l[i]+1;
            ans.pb(v[i]);
            cnt[i]++;
        }
        if(i < n-1 && cnt[i+1] < 2){
            if(v[i] != r[i] && r[i] == l[i+1]){
                ans.pb(r[i]);
                v[i+1] = r[i];
                cnt[i+1]++;
                cnt[i]++;
            }
        }
        if(cnt[i] == 1){
            if(v[i] == l[i]+1) ans.pb(l[i]+2);
            else ans.pb(l[i]+1);
        }
    }

    cout << ans.size() << endl;
    rep(ans.size()) cout << ans[i] << " ";
    cout << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}