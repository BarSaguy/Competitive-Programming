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
    int n; cin >> n;
    cout << n << endl;
    for(int i=0; i<n; i++){
        cout << i+1 << " ";
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