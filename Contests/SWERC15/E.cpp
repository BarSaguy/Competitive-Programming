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
const int MOD = 2147483647;

vi curl;
vi curr;
vi suml;
vi sumr;
void solve(){
    int n; cin >> n;
    curl.resize(n+1, 0);
    curr.resize(n+1, 0);
    suml.resize(n+1, 0);
    sumr.resize(n+1, 0);
    int l,r; cin >> l >> r; l--;r--;
    int ar = r;

    rep(i, l, r+1) {suml[i] = 1; sumr[i] = 1;}
    //sumr[ar] = 0;

    rep(j, n-1){
        cin >> ar;ar--;
        repr(i, n, ar+1){
            sumr[i] = sumr[i] + sumr[i+1];
        }

        rep(i, 1, ar){
            suml[i] = suml[i] + suml[i+1];
        }
    }
    int x=6;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}