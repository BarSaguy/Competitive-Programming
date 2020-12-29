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
    int n, c0, c1, h; cin >> n >> c0 >> c1 >> h;
    string s; cin >> s;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(c0 < c1){
            if(s[i] == '0') ans += c0;
            else ans += min(c1, c0+h);
        }
        else{
            if(s[i] == '1') ans += c1;
            else ans += min(c0, c1+h);
        }
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