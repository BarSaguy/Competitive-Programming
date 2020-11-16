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
    int n, m; cin >> n >> m;
    string s1, s2; cin >> s1 >> s2;
    vvi a(n+1);
    for(int i=0; i<n+1; i++) a[i].resize(m+1, 0);
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                a[i][j] = max(max(a[i-1][j-1]+2, a[i-1][j]-1), a[i][j-1]-1);
            else
                a[i][j] = max(max(a[i][j-1]-1, a[i-1][j]-1), a[i-1][j-1]-2);
            if(a[i][j] < 0) a[i][j] = 0;
            if(ans < a[i][j]) ans = a[i][j];
        }
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