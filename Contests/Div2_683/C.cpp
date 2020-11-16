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
    int n, W; cin >> n >> W;
    vii w;
    for(int i=0; i<n; i++){
        int e; cin >> e;
        w.push_back({e, i});
    }
    sort(w.begin(), w.end());
    int sum = 0;
    vi idx;
    int d = 2;
    for(int i=n-1; i>=0; i--){
        if(w[i].first > W) continue;
        sum += w[i].first;
        idx.push_back(w[i].second);
        if(sum >=W/2 + W%2) break;
    }

    if(sum < W/2 + W%2){
        cout << -1 << endl;
        return;
    }
    cout << idx.size() << endl;
    for(int i=0; i<idx.size();i++){
        cout << idx[i]+1 << " ";
    }
    cout << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}