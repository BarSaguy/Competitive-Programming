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
#define all(arr) (arr.begin(), arr.end())
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

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    set<int> st;
    int num = 0;
    int m;
    int sft = 0;
    if(k > 30)
        sft = 30;
    else
       sft = (k-1);
    m = 1LL << sft;
    vi good(n);
    int cntr=0;
    rep(n){
        if(s[i] == '1') cntr = k-1-sft;
        else cntr--;
        if(cntr <= 0) good[i] = 1;
    }
    rep(k){
        num = num % m;
        num = num*2 + !(s[i]-'0');
    }
    if(good[k-(sft+1)])
        st.insert(num);
    
    rep(i, k, n){
        num = num % m;
        num = num*2 + !(s[i]-'0');
        if(good[i+1-(sft+1)])
            st.insert(num);
    }
    string ans2;
    rep(m*2){
        if(st.find(i) == st.end()){
            string ans;
            while(i){
                ans.push_back(i%2 + '0');
                i /= 2;
            }
            while(ans.size() < k) ans.push_back('0');
            
            repr(k) ans2.push_back(ans[i]);
            
            break;
        }
    }
    if(ans2.size() > 0) cout << "YES" << endl << ans2 << endl;
    else cout << "NO" << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}