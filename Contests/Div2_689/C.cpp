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

const int INF = 1e18;

void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    for(int i=0; i<n; i++) {cin >> a[i];a[i]--;}
    int idx = n-1;
    while(idx >=0 && a[idx] == idx) idx--;
    vi r(m);
    vector<double> p(m);
    for(int i=0; i<m; i++){
        cin >> r[i] >> p[i];
        r[i]--;
    }
    double ans = 1;
    if(idx == -1) ans = 0;
    bool first = true;
    for(int i=0; i<m; i++){
        if(r[i] >= idx && idx != -1){
            if(first) {ans = 1-p[i];first=false;}
            else ans *= (1-p[i]);
        }
    }
    cout << 1-ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}