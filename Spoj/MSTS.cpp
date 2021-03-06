#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define pqii priority_queue<ii>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, s, n) for (int i = (s); i < (n); i++)
#define repr(...) GET_MACRO(__VA_ARGS__, repr3, repr2, repr1)(__VA_ARGS__)
#define repr1(n) for (int i = (n)-1; i >= 0; i--)
#define repr2(i, n) for (int i = (n)-1; i >= 0; i--)
#define repr3(i, n, s) for (int i = (n)-1; i >= (s); i--)
#define x first
#define y second
#define pb push_back

const int INF = 1e18;
const int MOD = 31011;

vi p, r;

void make_set(int v){
    p[v] = v;
    r[v] = 0;
}

int find_p(int v){
    if(p[v] == v) return v;
    return p[v] = find_p(p[v]);
}

void uni_sets(int u, int v){
    int a = find_p(u), b = find_p(v);
    if(a != b){
        if(r[a] < r[b]) swap(a, b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
    }
}

struct Edge{
    int u, v, weight;
    Edge(int a, int b, int c){
        u=a;v=b;weight=c;
    }
    bool operator<(const Edge& other){
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;
vector<vector<ii>> g;

int visit_idx = 0;
vi visited;

int dfs(int c, int dest){
    if(visited[c] >= visit_idx) return -INF;
    visited[c] = visit_idx;
    int ans = -INF;
    for(auto nei : g[c]){
        if(nei.x == dest){
            return nei.y;
        }
        int r = dfs(nei.x, dest);
        if(r != -INF){
            ans = max(ans, r);
            ans = max(ans, nei.y);
        }
    }
    return ans;
}

vector<vector<double>> mat;

vector<Edge> result;

/*
Not working.
Working algorithm (Based on kruskal): 
Split the edges into sets according to their cost. Then, for each cost starting with the smallest one, consider those edges only.
They form several components. For each such component, compute the number of spanning trees using the Matrix Tree Theorem
(this is the number of ways to pick some of these edges into the MST when doing Kruskal's algorithm), multiply the result by this value,
and then merge the component into a single vertex.
*/

void solve(){
    int n, m; cin >> n >> m;
    p.resize(n);
    r.resize(n);
    g.resize(n);
    mat.resize(n);
    rep(n) mat[i].resize(n, 0);
    visited.resize(n, 0);
    rep(m){
        int a,b,c; cin >> a >> b >> c;
        a--;b--;
        edges.push_back(Edge(a, b, c));
        //g[a].push_back({b, c});
        //g[b].push_back({a, c});
    }
    rep(n) make_set(i);
    sort(all(edges));
    for (Edge e : edges) {
        if (find_p(e.u) != find_p(e.v)) {
            g[e.u].pb({e.v, e.weight});
            g[e.v].pb({e.u, e.weight});
            uni_sets(e.u, e.v);
            result.pb(e);
        }
        else{
            visit_idx++;
            if(dfs(e.u, e.v) == e.weight) result.pb(e);
        }
    }

    rep(result.size()){
        Edge e = result[i];
        mat[e.u][e.u]++;
        mat[e.v][e.v]++;
        mat[e.u][e.v]=-1;
        mat[e.v][e.u]=-1;
    }

    double det = 1;
    const double EPS = 1E-9;
    n = n-1;
    rep(n){
        int k = i;
        rep(j, i+1, n){
            if(abs(mat[j][i]) > abs(mat[k][i]))
                k = j;
        }
        if(abs(mat[k][i]) < EPS){
            det = 0; break;
        }
        swap(mat[i], mat[k]);
        if(i != k) det = -det;
        det = (det * mat[i][i]);
        if((int)det == det) det = (int)det%MOD;
        rep(j, i+1, n)
            mat[i][j] /= mat[i][i];
        rep(j, n)
            if (j != i && abs(mat[j][i]) > EPS)
                rep(k, i+1, n)
                    mat[j][k] -= mat[i][k] * mat[j][i];
    }
    cout << (int)det << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}