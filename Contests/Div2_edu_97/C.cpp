#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vi t;
vvi h;
const int INF = 1e18+7;

int dp(int c, int T){
    if(h[c][T] != -1)
        return h[c][T];
    int result;
    if(c == t.size()-1){
        if(T > t[c]) return T-t[c];
        else return 0;
    }
    if(T >= t[c]) result = T-t[c] + dp(c+1, T+1);
    else result = min(abs(T-t[c]) + dp(c+1, T+1), dp(c, T+1));
    h[c][T] = result;
    return result;
}

void solve(){
    int n; cin >> n;
    t.clear();
    t.resize(n);
    h.clear();
    h.resize(n);
    for(int i=0; i<n;i++){
        cin >> t[i];
        h[i].resize(500, -1);
    }
    
    sort(t.begin(), t.end());

    cout << dp(0, 1) << endl; 
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}