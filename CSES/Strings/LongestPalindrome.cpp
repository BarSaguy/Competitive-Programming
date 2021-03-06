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
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)

const int INF = 1e18;

void solve(){
    string s; cin >> s;
    int n=  s.size();
    vi d1(n), d2(n);
    for(int i=0, l=0, r=-1; i<n; i++){
        int k = (i>r) ? 1 : min(d1[l+r-i], r-i+1);
        while(i-k >= 0 && i+k < n && s[i-k] == s[i+k]){
            k++;
        }
        d1[i] = k--;
        if(i+k > r){
            l = i-k;
            r = i+k;
        }
    }

    for(int i=0, l=0, r=-1; i<n; i++){
        int k = (i>r) ? 0 : min(d2[l+r-i+1], r-i+1);
        while(i-k-1 >= 0 && i+k < n && s[i-k-1] == s[i+k])
            k++;
        d2[i] = k--;
        if(i+k > r){
            l = i-k-1;
            r = i+k;
        }
    }

    int max_s=0;
    int l=0, r=0;
    rep(n){
        int s = d1[i] * 2 - 1;
        if(s  > max_s){
            max_s = s;
            l = i - d1[i];
            r = i + d1[i];
        }
    }

    rep(n){
        int s = d2[i]*2;
        if(s > max_s){
            max_s = s;
            l = i-d2[i] - 1;
            r = i+d2[i];
        }
    }
    // cout << max_s << endl;

    rep(i, l+1, r){
        cout << s[i];
    }
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}