#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>

const int MOD = 1e9 + 7;

vvi g;
vi visited;
vvvi ans;

vi leaves;
queue<int> q;


bool is_leave(int c){
    for(auto nei : g[c]){
        if(!visited[nei]) return false;
    }
    return true;
}

void find_leaves(int cur){
    if(visited[cur]) return;
    visited[cur] = true;
    if(is_leave(cur)) {leaves.push_back(cur);q.push(cur);}

    for(auto nei : g[cur]){
        find_leaves(nei);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    ans.resize(n);
    g.resize(n);
    visited.resize(n, false);
    for(int i=0; i<n-1; i++){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    find_leaves(0);
    for(int i=0; i<n; i++)visited[i] = false;

    int k, x; cin >> k >> x;

    for(int i=0; i<leaves.size();i++){
        ans[leaves[i]].resize(3);
        for(int j=0; j<3; j++) ans[leaves[i]][j].resize(x+1, 0);
        ans[leaves[i]][0][0] = k-1;
        ans[leaves[i]][1][1] = 1;
        ans[leaves[i]][2][0] = m-k;
        visited[leaves[i]] = true;
        for(auto nei: g[leaves[i]]){
            if(!visited[nei])
                q.push(nei);
            visited[nei] = true;
        }
    }
    int last = 0;
    while(!q.empty()){
        int t = q.front(); q.pop();
        last = t;
        ans[t].resize(3);
        for(int j=0; j<3; j++) ans[t][j].resize(x+1, 0);
        bool first = true;
        for(auto nei: g[t]){
            if(visited[nei]){
                if(first){
                    for(int j=0; j<x+1; j++){
                        ans[t][0][j] = ((ans[nei][0][j] + ans[nei][1][j]) % MOD + ans[nei][2][j]) % MOD*(k-1) % MOD;
                        if(j > 0)
                            ans[t][1][j] = ans[nei][0][j-1];
                        ans[t][2][j] = (ans[nei][0][j] + ans[nei][2][j]) % MOD* (m-k) % MOD;
                    }
                }
                else{
                    for(int j=0; j<x+1; j++){
                        for(int j2=0; j<x+1-j; j++){
                            ans[t][0][j+j2] = ans[t][0][j] *((ans[nei][0][j2] + ans[nei][1][j2] + ans[nei][2][j2]) % MOD) % MOD;
                            if(j > 0)
                                ans[t][1][j+j2] = (ans[t][1][j] * ans[nei][0][j2]) % MOD;
                            ans[t][2][j+j2] = (ans[t][1][j] * (ans[nei][0][j2] + ans[nei][2][j2]) % MOD) % MOD * (m-k) % MOD; 
                        }
                    }
                }
            }
            else{
                visited[nei] = true;
                q.push(nei);
            }
        }
    }
    int sum = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<x+1; j++){
            sum += ans[last][i][j];
            sum = sum % MOD;
        }
    }
    cout << sum << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;// cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}