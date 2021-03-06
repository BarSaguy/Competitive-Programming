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

const int INF = 1e18;
const int MOD = (int)1e9+7;

void solve(){
    int n; cin >> n;
    vi x(n);
    rep(n) cin >> x[i];
    vi cnt(60, 0);
    rep(n){
        int t = x[i];
        int idx=0;
        while(t){
            cnt[idx] += t%2;
            t /= 2;
            idx++;
        }
    }
    int ans = 0;
    rep(n){
        vi cur(60, 0);
        int t = x[i];
        int idx=0;
        while(t){
            cur[idx] += t%2;
            t /= 2;
            idx++;
        }
        int a=0;
        rep(j, 60){
            if(cur[j]){
                a = (a + (1LL << j)%MOD * cnt[j]%MOD) % MOD;
                //a = (a + (1 << j) * cnt[j]);
            }
        }
        int b=0;
        rep(j, 60){
            if(cnt[j]){
                if(cur[j]){
                    b = (b + (1LL << j)%MOD * n%MOD) % MOD;
                    //b = (b + (1 << j)*n);
                }
                else{
                    b = (b + (1LL << j)%MOD * cnt[j]%MOD)%MOD;
                    //b = (b + (1 << j)*cnt[j]);
                }
            }
        }
        ans = (ans + ((a*b)%MOD))%MOD;
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}