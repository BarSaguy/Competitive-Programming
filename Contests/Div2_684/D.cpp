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
const int mxN = 1e5;

int n, m, k; 
vvi g;
vii deg;
vi cand;
int mat[(int)1e5][(int)1e5];

void fix_deg(int u, bool always){
    if(deg[u].first < k-1 || always){
        deg[u].first = INF;
        for(auto nei : g[u]){
            deg[nei].first--;
            mat[nei][u] = 0;
            mat[u][nei] = 0;
            fix_deg(nei, false);
        }
    }
}

void remove_less(){
    for(int i=0; i<n; i++){
        fix_deg(i, false);
    }
}

bool check_clique(int cur){
    cand.clear();
    cand.push_back(cur);
    for(auto nei: g[cur]){
        if(mat[cur][nei])
            cand.push_back(nei);
    }
    for(int i=0; i<cand.size(); i++){
        for(int j=0; j<cand.size(); j++){
            if(i == j) continue;
            if(mat[i][j] == 0){
                return false;
            }
        }
    }
    cout << 2 << " " << cand.size() << endl;
    for(int i=0; i<cand.size();i++){
        cout << cand[i] << " ";
    }
    cout << endl;
    return true;
}

void solve(){
   cin >> n >> m >> k;
    if(k > sqrt(2*m)){
        cout << -1 << endl;
        return;
    }
    g.clear();
    g.resize(n);
    deg.clear();
    for(int i=0; i<n; i++) deg.push_back({0,i});
    for(int i=0; i<m; i++){
        int u,v; cin >> u >>v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        mat[u][v] = 1;
        mat[v][u] = 1;
        deg[u].first++;
        deg[v].first++;
    }
    remove_less();
    ii m = deg[0];
    for(int i=0; i<n; i++){
        if(m.first > deg[i].first)
            m = deg[i];
    }
    vi ans;
    while(m.first != INF){
        if(m.first >= k){
            for(int i=0; i<n; i++){
                if(deg[i].first >= k)
                    ans.push_back(deg[i].second);
            }
            cout << 1 << " " << ans.size() << endl;
            for(int i=0; i<ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
            return;
        }
        else{
            if(check_clique(deg[0].second))
                return;
            fix_deg(deg[0].second, true);
        }
        for(int i=0; i<n; i++){
            if(m.first > deg[i].first)
                m = deg[i];
        }
    }
    cout << -1 << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}