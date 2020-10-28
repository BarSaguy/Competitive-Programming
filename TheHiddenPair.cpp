#include <bits/stdc++.h>

using namespace std;

vector<int> near;
vector<bool> visited;
vector<vector<int>> edges;
int n; 

void dfs(int node, int depth, bool exactly){
    if(visited[node])
        return;
    visited[node] = true;
    if(!exactly && depth <= 0)
        near.push_back(node + 1);
    if(exactly && depth == 0){
        near.push_back(node + 1);
        return;
    }
    for(int nei : edges[node]){
        dfs(nei, depth-1, exactly);
    }
}

void query(){
    cout << "? " << near.size();
    for(int i=0; i<near.size(); i++)    
        cout << " " << near[i];
    cout << endl;
}

void clear(){
    near.clear();
    for(int i=0; i<n; i++)
        visited[i] = false;
}

void solve(){
    cin >> n;
    visited.resize(n);
    edges.clear();
    edges.resize(n);
    for(int j=0; j<n-1; j++){
        int u, v; cin >> u >> v;
        u--;v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int x, d, min_dist, k;
    cout << "? " << n;
    for(int i=0; i<n; i++)
        cout << " " << i+1;
    cout << endl;
    cin >> x >> min_dist;
    x--;

    int start = min_dist/2, end = min_dist + 1, mid, ans = 1;
    int a1 = x + 1, a2; 
    while(start < end){
        mid = (start + end)/2;
        clear();
        dfs(x, mid, true);
        if(near.size() == 0) end = mid;
        else{
            query();
            cin >> k >> d;
            if(d == min_dist) a1=k, start = mid + 1;
            else end = mid;
        }
    }
    //if(mid > min_dist/2)
    //    mid = min_dist - mid;
    //cout << "ans = " << ans << " " << min_dist << endl;

    //if(ans == 0)
    //    a1 = x + 1;
    // else{
    //    clear();
    //    dfs(x, ans, true);
    //     query();
    //    cin >> a1 >> d;
    // }
    clear();
    dfs(a1-1, min_dist, true);
    query();
    cin >> a2 >> d;
    cout << "! " << a1 << " " << a2 << endl;
    string answer;
    cin >> answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;

    for(int i=0; i<t; i++){
        solve();    
    }

    return 0;
}