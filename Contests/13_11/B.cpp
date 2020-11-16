#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>


vvi g;
const int INF = 1e18;

vi sz;
vi arr;
vi curIdx;
vi maxIdx;
vi maxN;
vi idx;

vector<priority_queue<int>> pq;
vector<priority_queue<int>> pq2;

void dfs(int cur){
    arr.push_back(cur);
    curIdx[cur] = arr.size()-1;
    while(!pq[cur].empty()){
        int t = -pq[cur].top(); pq[cur].pop();
        dfs(t);
    }
}

void find_max(int cur){
    if(pq2[cur].empty())
        maxIdx[cur] = curIdx[cur];
    while(!pq2[cur].empty()){
        int t = -pq2[cur].top(); pq2[cur].pop();
        find_max(t);
        maxIdx[cur] = maxIdx[t];
    }
}

void query(int u, int k){
    if(curIdx[u]+k > maxIdx[u])
        cout << -1 << endl;
    else
        cout << arr[curIdx[u] + k]+1 << endl;
}

void solve(){
    int n, q;  cin >> n >> q;
    g.resize(n);
    sz.resize(n, 1);
    pq.resize(n);
    pq2.resize(n);
    curIdx.resize(n);
    maxIdx.resize(n);
    for(int i=1; i<n; i++){
        int p; cin >> p;p--;
        g[p].push_back(i);
        pq[p].push(-i);
        pq2[p].push(-i);
    }
    dfs(0);
    find_max(0);

    for(int i=0; i<q; i++){
        int u, k; cin >> u >> k; u--;k--;
        query(u, k);
    }

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}