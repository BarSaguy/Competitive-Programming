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

const int INF = 1e18;

struct iigreater
{
    bool operator()( const ii& lhs, const ii& rhs ) const {
        if(lhs.first == rhs.first)
            return lhs.second < rhs.second;
        return lhs.first > rhs.first;
    }
};

vi x;
vi y;
vii toys;
pqii pq;
vii toys_for_small;
int a, b, t; 

bool check(int m){
    int extra = m;
    int idx=0;
    pq = pqii();
    toys_for_small.clear();
    for(int i=0; i<toys.size();i++){
        if(idx < a-1 && toys[i].first < x[idx+1]){extra += m;idx++;}
        if(extra == -1) return false;
        if(a == 0){
            toys_for_small.push_back({toys[i].second, toys[i].first});
            continue;
        }
        if(toys[i].first > x[idx]){
            toys_for_small.push_back({toys[i].second, toys[i].first});
        }
        else if(toys[i].first < x[idx] && extra > 0){
            extra--;
            pq.push({-toys[i].second, toys[i].first});
        }
        else{
            pq.push({-toys[i].second, toys[i].first});
            ii top = pq.top();pq.pop();
            toys_for_small.push_back({-top.first, top.second});
        }
    }
    sort(all(toys_for_small), greater<>());
    extra = m;
    idx = 0;
    for(int i=0; i<toys_for_small.size();i++){
        if(b == 0) return false;
        if(idx < b-1 && toys_for_small[i].first < y[idx+1]) {extra += m;idx++;}
        if(toys_for_small[i].first < y[idx] && extra > 0){
            extra--;
        }
        else
        {
            return false;
        }
        
    }
    return true;
}


void solve(){
    cin >> a >> b >> t;
    x.resize(a);
    for(int i=0; i<a; i++) cin >> x[i];
    y.resize(b);
    for(int i=0; i<b; i++) cin >> y[i];
    vi w(t), s(t);
    for(int i=0; i<t; i++){
        cin >> w[i] >> s[i];
        toys.push_back({w[i], s[i]});
    }
    sort(all(x), greater <>());
    sort(all(y), greater <>());
    sort(all(toys), iigreater());
    int l=1, r=1e6+1, m;
    int ans = -1;
    //check(3);
    while(l < r){
        m = (l+r)/2;
        if(check(m)){
            ans = m;
            r = m;
        }
        else{
            l = m+1;
        }
    }
    cout << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}