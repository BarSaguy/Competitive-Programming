#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vector<int>>
#define vvii vector<vii>

int n, m, k;

vvii graph;
vvi min_dist;


void dijkstra(int source){
    priority_queue<ii, vii, greater<ii>> pq;
    pq.emplace(0LL,source);
    min_dist[source][source] = 0;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        for(auto nei: graph[top.second]){
            if(min_dist[source][nei.second] > min_dist[source][top.second] + nei.first){
                min_dist[source][nei.second] = min_dist[source][top.second] + nei.first;
                pq.emplace(min_dist[source][nei.second], nei.second);
            }
        }
    }
}




int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    vii delivery;
    vii edges;
    graph.resize(n);
    for(int i=0; i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
        edges.emplace_back(u, v);
    }
    min_dist.resize(n);
    for(int i=0; i<n;i++){
        min_dist[i].resize(n, (int)10e9+1);
        dijkstra(i);
    }

    for(int i=0; i<k;i++){
        int a,b; cin >> a >> b;
        a--;b--;
        delivery.emplace_back(a, b);
    }
    int sum, min_sum = (int)10e17;
    for(int i=0; i<m;i++){
        sum = 0;
        int a = edges[i].first, b = edges[i].second;
        for(int j=0; j<k;j++){
            int u = delivery[j].first, v = delivery[j].second;
            int dist_a_u = min(min_dist[a][u], min_dist[b][u]);
            int dist_a_v = min(min_dist[a][v], min_dist[b][v]);
            int dist_u_v = min(min_dist[u][v], dist_a_u + dist_a_v);
            sum += dist_u_v;
        }
        if(sum < min_sum)
            min_sum = sum;
    }

    cout << min_sum << endl;

    return 0;
}







// Dijkstra nlogn
// from each k: n^2logn

