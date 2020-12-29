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
    int a,b; cin >> a >> b;
    int g = __gcd(a, b);
    vi d;
    for(int i=1; i<=sqrt(g); i++){
        if(g%i == 0){
            if(g/i == i) d.push_back(i);
            else{d.push_back(i);d.push_back(g/i);}
        }
    }
    sort(all(d));
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int l, r; cin >> l >> r;
        int ans = *(upper_bound(all(d), r)-1);
        if(ans >= l) cout << ans << endl;
        else cout << -1 << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}