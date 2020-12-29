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
    int n, k; cin >> n >> k;
    vi a(n*k);
    for(int i=0; i<n*k; i++){
        cin >> a[i];
    }
    int ans = 0;
    int cnt = 0;
    int c = 0;
    for(int i=n*k-1; i>=0; i--){
        if(cnt == n/2){ans += a[i];cnt = 0;c++;}
        else{
            cnt++;
        }
        if(c == k) break;
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}