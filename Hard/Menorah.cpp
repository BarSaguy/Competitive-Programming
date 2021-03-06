#include <bits/stdc++.h>

using namespace std;

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

const int INF = 1e9+1;


int calc_options(vi& intervals, bool swap){
    int ret2 = INF;
    if(swap) ret2 = calc_options(intervals, false);
    int ret=0;
    rep(intervals.size()){
        if(intervals[i] & 4 && swap){
            intervals[i] = 4;
        }
    }

    int c1=0, c2=0;
    rep(intervals.size()){
        if(intervals[i] & 1) c1++;
        else if(intervals[i] & 2) c2++;
        else if(intervals[i] == 4) {
            if(!swap) return INF;
            if(max(c1, c2) != 0) ret += min(c1,c2) + 1;
            c1 = 0;
            c2 = 0;
        }
    }
    if(max(c1, c2) != 0) ret += min(c1,c2) + 1;
    if(swap) ret = min(1+ret, ret2);
    return ret;
}


int GetMinMoves(int N, string A, string B){
    int n=N;
    string a=A, b=B;
    rep(n) a[i] = a[i]-'0';
    rep(n) b[i] = b[i] - '0';
    int ans = 0;
    int options=0;
    vi intervals;
    rep(n){
        int new_options = 0;
        if(b[i] == 1) new_options |= 1;
        else if(b[i] == 0) new_options |= 2;
        if(b[i] == !a[i]) new_options |= 4;
        int old_options = options;
        options &= new_options;
        if(a[i] != b[i]){
            if(options == 0){
                intervals.push_back(old_options);
                options = new_options;
            }
        }
        else{
            if(options == 0){
                intervals.push_back(old_options);
                ans += calc_options(intervals, true);
                intervals.clear();
            }
        }
    }
    intervals.push_back(options);
    ans += calc_options(intervals, true);

    return ans;
}

// void solve(){
//     int n; cin >> n;
//     string a, b; cin >> a >> b;
//     cout << GetMinMoves(n, a, b) << endl;
// }

// int32_t main(){
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     int t=1;
//     //cin >> t;
//     while(t--) solve();
//     return 0;
// }