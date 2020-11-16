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
    vi b(n);
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j == i) continue;
            if(b[j] == b[i]){
                cout <<"YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    //int t=1;
    for(int i=0; i<t; i++) solve();
    return 0;
}