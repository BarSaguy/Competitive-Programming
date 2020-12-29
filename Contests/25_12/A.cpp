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
    int n; cin >> n;
    vii b(n);
    for(int i=0; i<n; i++){
        int a; cin >> a;
        b[i] = {a, i};
    }
    sort(all(b));
    if(n <= 3){cout << 0 << endl; return;}
    int ans1 = b[1].first - b[0].first;
    int ans2 = b[2].first - b[0].first;
    int ans3 = b[2].first - b[1].first;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(int i=2; i<n; i++){
        int c1 = (b[i].first - b[0].first) / i;
        int c2 = (b[i].first - b[0].first) / (i-1);
        if(c1 == ans1) cnt1++;
        if(c2 == ans2) cnt2++;
        if(c2 == ans3) cnt3++;
    }

    cout << cnt1 << endl;
    cout << cnt2 << endl;
    cout << cnt3 << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}