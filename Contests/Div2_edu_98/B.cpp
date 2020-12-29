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


void solve(){
    int n; cin>>n;
    vi a(n);
    for(int i=0; i<n; i++) cin >>a[i];
   // if(n == 2) cout << 0 << endl;
    int m = a[0];
    for(int i=0; i<n; i++){
        if(m < a[i]){m = a[i];}
    }
    int ans = 0;
    int f = 0;
    int s = 0;
    for(int i=0; i<n; i++){
        s += m-a[i];
    }
    cout << abs(s-m) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}