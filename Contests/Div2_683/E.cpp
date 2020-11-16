#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>

const int INF = 1e18;

vi c;

void solve(){
    int n; cin >> n;
    vi a(n);
    c.resize(32, 0);
    vi sum_below(32);
    vi sum_above(32);
    vi diff_above(32);
    int m = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<32; i++) c[i] = 0;
    for(int i=0; i<n; i++){
        int t = a[i];
        for(int j=0; j<32; j++){
            if(t == 0){
                c[j]++;
                break;
            }
            t /= 2;
        }
    }
    int sum = 0;
    for(int i=0; i<32; i++){
        sum_below[i] = sum;
        sum += c[i];
    }
    sum = 0;
    int diffc = 0;
    for(int i=31; i>=0; i--){
        sum_above[i] = sum;
        diff_above[i] = diffc;
        if(c[i] != 0)  diffc++;
        sum += c[i];
    }
    int ans = INF;
    for(int i=0; i<32; i++){
        int t = sum_below[i]-1;
        if(t < 0) t = 0;
        if(ans >sum_above[i]-diff_above[i]+t)
            ans = sum_above[i]-diff_above[i]+t;
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}