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
    int n; cin >> n;
    int mx = n;
    int cnt = 0;
    cout << n+5 << endl;
    //vi a(n+1);
    //rep(n+1) a[i] = i;
    repr(i, n, 2){
        if((i-1)*(i-1) < mx){
            cout << mx << " " << i << endl;
            cout << mx << " " << i << endl;
            //a[mx] = a[mx] / a[i] + a[mx]%a[i]!=0;
            //a[mx] = a[mx] / a[i]+ a[mx]%a[i]!=0;
            cnt+=2;
            mx = i;
        }
        else{
            cout << i << " " << mx << endl;
            //a[i] = a[i] / a[mx]+ a[i]%a[mx]!=0;
            cnt++;
        }
    }
    //rep(n) cout << a[i];
    while(cnt < n+5) {cout << 1 << " " << 2 << endl;cnt++;}
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}