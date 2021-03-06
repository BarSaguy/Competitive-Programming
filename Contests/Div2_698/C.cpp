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

int solve(){
    int n; cin >> n;
    vi a(2*n); rep(2*n) cin >> a[i];
    sort(all(a));
    int c = 0;
    rep(2*n-1){
        if(a[i] == a[i+1]) c++;
        else{
            if(c != 1){
            return 0;
            }
            c=0;
        }
    }
    if(c != 1){
        return 0;
    }
    vi b(n);
    rep(2*n){
        if(i%2 == 0) b[i/2] = a[i]; 
    }

    sort(all(b));
    reverse(all(b));
    c=0;
    rep(n){
        if(b[i] % 2 != 0){
            return 0;
        }
        if(b[i]-c <= 0) return 0;
        if((b[i]-c) % (2*(n-i)) != 0){
            return 0;
        }
        int k = (b[i] - c) / (2*(n-i));
        // if(k < 1){
        //     return 0;
        // }
        c += 2*k;
    }
    return 1;  
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) cout << (solve()?"YES":"NO") << endl;
    return 0;
}