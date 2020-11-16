#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>


vvi g;
vi a;
vi maxST;
vi sumST;
vi visited;
const int INF = 1e17;

int calc_max(int cur){
    if(visited[cur])return -INF;
    visited[cur] = true;
    int ans=-INF;
    for(auto nei: g[cur]){
        if(visited[nei]) continue;
        int r = calc_max(nei);
        ans = max(ans, r);
    }
    maxST[cur] = max(sumST[cur], ans);
    return maxST[cur];
}

void calc_sum(int cur){
    if(visited[cur])return;
    visited[cur] = true;
    int s = 0;
    for(auto nei: g[cur]){
        if(visited[nei]) continue;
        calc_sum(nei);
        s += sumST[nei];
    }
    sumST[cur] = s + a[cur];
}


int find_max(int cur){
    if(visited[cur]) return -INF;
    visited[cur] = true;
    int ans=-INF; int m1=-2*INF, m2=-2*INF;
    if(g[cur].size() < 2){
        if(g[cur].size() == 1)
            return find_max(g[cur][0]);
        return -INF;
    }
    for(auto nei: g[cur]){
        if(visited[nei]) continue;
        if(m1 < maxST[nei]){
            m2 = m1;
            m1 = maxST[nei];
        }
        else if(m2 < maxST[nei]){
            m2 = maxST[nei];
        }
    }
    ans = m1 + m2;
    for(auto nei: g[cur]){
        if(visited[nei]) continue;
        ans = max(find_max(nei), ans);
    }
    return ans;
}


void solve(){
    int n; cin >> n;
    g.resize(n);
    a.resize(n);
    maxST.resize(n, 0);
    sumST.resize(n, 0);
    visited.resize(n, false);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v; u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc_sum(0);
    for(int i=0; i<n; i++) visited[i] = false;
    calc_max(0);
    for(int i=0; i<n; i++) visited[i] = false;
    int ans = find_max(0);
    if(ans <= -INF)
        cout << "Impossible" << endl;
    else
    {
        cout << ans << endl;
    }
    
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}