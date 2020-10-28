#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

int dijkstra(int start){

}

vvi g;

void solve(){
    int n; cin >> n;
    vi h(n);
    g.resize(n);

    for(int i=0; i<n-1; i++){
        g[i].push_back(i+1);
    }

    for(int i=0; i<n; i++){
        cin >> h[i];
    }
    int idx;


    dijkstra(0);
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}