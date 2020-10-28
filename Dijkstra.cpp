#include <bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;

// dest, weight
vector<vector<pi>> graph;
vector<int> min_dist;

void print_path(int source, int dest){
    stack<int> s;
    int curr = dest;
    int d = min_dist[dest];
    s.push(curr);
    while(curr != source){
        for(auto nei: graph[curr]){
            if(min_dist[nei.second] == d - nei.first){
                curr = nei.second;
                d = d - nei.first;
                s.push(curr);
            }
        }
    }
    while(!s.empty()){
        cout << s.top() + 1 << " ";
        s.pop();
    }
}

int dijkstra(int source, int dest){
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(0LL,source);
    min_dist[source] = 0;
    while(!pq.empty()){
        pi top = pq.top();
        pq.pop();
        if(top.second == dest){
            print_path(source, dest);
            return min_dist[dest];
        }
        for(auto nei: graph[top.second]){
            if(min_dist[nei.second] > min_dist[top.second] + nei.first){
                min_dist[nei.second] = min_dist[top.second] + nei.first;
                pq.emplace(min_dist[nei.second], nei.second);
            }
        }
    }
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    graph.resize(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }
    min_dist.resize(n, (int)10e12);
    if(dijkstra(0, n-1) == -1)
        cout << -1 << endl;
    //cout << dijkstra(0, n-1) << endl;

    return 0;
}