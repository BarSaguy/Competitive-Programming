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
    vvi a(n);
    for(int i=0; i<n; i++){
        a[i].resize(n);
        for(int j=0; j<n; j++) cin >> a[i][j];
    }
    string s; cin >> s;
    int cnt1 = 0 , cnt2 = 0, flip1 = 0, flip2 = 0;
    for(int i=0; i<m; i++){
        if(s[i] == 'R') cnt1++;
        else if(s[i] == 'L') cnt1--;
        else if(s[i] == 'U') cnt2--;
        else if(s[i] == 'D') cnt2++;
        else if(s[i] == 'I') flip1 = !flip1;
        else if(s[i] == 'C') flip2 = !flip2;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int idx_i = (i - cnt1+n)%n;
            int idx_j = (j - cnt2+n)%n;
            if(flip2) idx_i = n-1-idx_i;
            if(flip1) idx_j = n-1-idx_j;
            cout << a[idx_i][idx_j] << " ";
        }
        cout << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}