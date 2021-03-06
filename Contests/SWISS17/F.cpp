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

int tot, nights, stays; 

vii idx;
vector<pair<ii, int>> a;
int dp1[51][51][370];
int dp2[51][51][370];
int h, m;

int solve_nights(){
    int ans = INF;
    rep(m){
        auto it1 = idx[i];
        auto it2 = a[it1.y];
        int cnt = it1.x - it2.x.y;
        int id = it2.x.x;
        rep(j, 51){
            int cnt2 = cnt+j;
            if(cnt2 > nights) cnt2=nights;
            rep(other_id, 51){
                int r = it2.x.y;
                if(r > 0)
                    dp1[id][cnt2][it1.x] = min(dp1[id][cnt2][it1.x], dp1[id][cnt2][it1.x-1]);
                if(other_id != id)
                    dp1[id][cnt2][it1.x] = min(dp1[id][cnt2][it1.x], dp1[other_id][j][r] + it2.y);
                else if(r > 0)
                    dp1[id][cnt2][it1.x] = min(dp1[id][cnt2][it1.x], dp1[other_id][j][r-1] + it2.y);
            }
            if(cnt2 == nights) ans = min(ans, dp1[id][cnt2][it1.x]);
        }
    }
    cout << ans << endl;
    return ans;
}

int solve_stays(){
    int ans = INF;
    rep(m){
        auto it1 = idx[i];
        auto it2 = a[it1.y];
        int cnt = 1;
        int id = it2.x.x;
        rep(j, 51){
            int cnt2 = cnt+j;
            if(cnt2 > stays) cnt2=stays;
            rep(other_id, 51){
                int r = it2.x.y;
                if(r > 0)
                    dp2[id][cnt2][it1.x] = min(dp2[id][cnt2][it1.x], dp2[id][cnt2][it1.x-1]);
                if(other_id != id)
                    dp2[id][cnt2][it1.x] = min(dp2[id][cnt2][it1.x], dp2[other_id][j][r] + it2.y);
                else if(r > 0)
                    dp2[id][cnt2][it1.x] = min(dp2[id][cnt2][it1.x], dp2[other_id][j][r-1] + it2.y);
            }
            if(cnt2 == stays) ans = min(ans, dp2[id][cnt2][it1.x]);
        }
    }
    cout << ans << endl;
    return ans;
}

void solve(){
    cin >> tot >> nights >> stays;
    cin >> h >> m;
    rep(51){
        rep(j, 51){
            rep(k, 370){
                if(j == 0) dp1[i][j][k] = 0;
                else dp1[i][j][k] = INF;
            }
        }
    }
    rep(m){
        int id, b, e, c; cin >> id >> b >> e >> c; id--;
        idx.pb({e, i});
        a.pb({{id, b}, c});
    }
    sort(all(idx));

    int ans1 = solve_nights();
    rep(51){
        rep(j, 51){
            rep(k, 370){
                if(j == 0) dp2[i][j][k] = 0;
                else dp2[i][j][k] = INF;
            }
        }
    }
    int ans2 = solve_stays();
    if(ans1 == INF && ans2 == INF){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    if(ans1 < ans2){
        cout << "NIGHTS" << endl;
        

    }
    else{
        cout << "STAYS" << endl;

    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}

/*
200 50 10
50 2
1 10 65 100
3 15 80 200



*/