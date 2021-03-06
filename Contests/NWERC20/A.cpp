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
#define eb emplace_back

const int INF = 1e18;


vi place;
vi ans;
vi sum_in;
vi sum;
vi last_upd;
vi pos;
vi left_cnt;

void update_pos(int i, int day){
    if(last_upd[i] < day){
        sum[i] += (day-last_upd[i]) * place[i];
        last_upd[i] = day;
    }
}

void solve(){
    int n, w; cin >> n >> w;
    place.resize(w+1, 1);
    ans.resize(n, 0);
    sum_in.resize(n, 0);
    sum.resize(w+1, 0);
    last_upd.resize(w+1, -1);
    pos.resize(n, 0);

    rep(w){
        int k; cin >> k;
        vi upd;
        rep(j, k){
            int a; cin >> a; a--;
            update_pos(pos[a], i-1);
            update_pos(pos[a]+1, i-1);
            ans[a] += sum[pos[a]] - sum_in[a];
            place[pos[a]]++;
            pos[a]++;
            upd.pb(a);
        }
        for(int u : upd){
            update_pos(pos[u], i);
            sum_in[u] = sum[pos[u]];
            ans[u] += place[pos[u]];
        }
    }

    cout<<fixed<<setprecision(10);
    rep(n){
        update_pos(pos[i], w-1);
        ans[i] += sum[pos[i]] - sum_in[i];
        cout << (double)ans[i]/w << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}