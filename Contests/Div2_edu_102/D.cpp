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

const int INF = 1e18;

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi minl(n), minr(n), maxl(n), maxr(n);
    vi sum(n);
    int c = 0;
    rep(s.size()){
        if(s[i] == '+') c++;
        else if(s[i] == '-') c--;
        if(i > 0){
            maxl[i] = max(maxl[i-1], c);
            minl[i] = min(minl[i-1], c);
        }
        else{
            maxl[i] = c;
            minl[i] = c;
        }
        sum[i] = c;
    }
    c = 0;
    int c1=0;
    int c2=0;
    repr(s.size()){
        if(s[i] == '+') {c1++;c2++;}
        else if(s[i] == '-') {c1--;c2--;}
        c1 = min(0LL, c1);
        c2 = max(0LL, c2);
        maxr[i] = c2;
        minr[i] = c1;
        maxr[i] = c2;
        minr[i] = c1;
    }
    rep(m){
        int minN=INF, maxN=0;
        int l, r; cin >> l >> r; l--;r--;
        if(l > 0){
        minN = min(minN,minl[l-1]);
        maxN = max(maxN, maxl[l-1]);
        }
        if(r < n-1){
            int m1= minr[r+1];
            int m2 = maxr[r+1];
            if(l > 0) m1 += sum[l-1];
            if(l > 0) m2 += sum[l-1];
            minN = min(minN,m1);
            maxN = max(maxN, m2);
        }
        minN = min(minN, 0LL);
        maxN = max(maxN, 0LL);
        cout << max(maxN - minN+1, 1LL) << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}