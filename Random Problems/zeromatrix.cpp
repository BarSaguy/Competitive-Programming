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
    int n, m; cin >> n >> m;
    vvi mat(n, vi(m));
    rep(n) rep(j, m) cin >> mat[i][j];
    int ans = 0;
    vi d(m, -1);
    rep(n){
        vi l(m), r(m);
        rep(j, m){
            if(mat[i][j] == 1) d[j] = i;
        }
        vi st;
        rep(j, m){
            while(st.size() && d[st.back()] <= d[j]){
                st.pop_back();
            }
            l[j] = st.size() ? st.back(): -1;
            st.pb(j);
        }
        st.clear();
        repr(j, m){
            while(st.size() && d[st.back()] <= d[j]){
                st.pop_back();
            }
            r[j] = st.size() ? st.back(): m;
            st.pb(j);
        }
        rep(j, m){
            ans = max(ans, (i - d[j]) * (r[j] - l[j] - 1));
        }
    }
    cout << ans << endl;   
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}