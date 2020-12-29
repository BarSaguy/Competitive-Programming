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

vvi dp;
vvi a;
vvi s_left;
vvi s_right;
int n, m; 

void calc_dp(){
    for(int i=0; i<n; i++){
        for(int k=-1; k<(int)a[i].size(); k++){
            for(int p=a[i].size(); p>k; p--){
                int c = 0;
                if(k != -1)
                    c += s_left[i][k];
                if(p != a[i].size())
                    c += s_right[i][p];
                dp[i][k+1+a[i].size()-p] = max(dp[i][k+1+a[i].size()-p], c);
            }
        }
    }
}

vvi dp2;

int find_ans(int idx, int steps){
    if(steps == 0 || idx >= a.size()) return 0;
    if(dp2[idx][steps] != -1) return dp2[idx][steps];
    int ans = 0;
    for(int i=0; i<=a[idx].size() && i<=steps; i++){
        ans = max(ans, find_ans(idx+1, steps-i) + dp[idx][i]);
    }
    dp2[idx][steps] = ans;
    return ans;
}

void solve(){
    cin >> n >> m;
    a.resize(n);

    for(int i=0; i<n; i++){
        int sz; cin >> sz;
        a[i].resize(sz);
        for(int j=0; j<sz; j++) cin >> a[i][j];
    }

    s_left.resize(n);
    s_right.resize(n);
    for(int i=0; i<n; i++){
        int sz = a[i].size();
        s_left[i].resize(sz);
        s_left[i][0] = a[i][0];
        for(int j=1; j<sz; j++){
            s_left[i][j] = s_left[i][j-1] + a[i][j];
        }
        s_right[i].resize(sz);
        s_right[i][sz-1] = a[i][sz-1];
        for(int j=sz-2; j>= 0; j--){
            s_right[i][j] = s_right[i][j+1] + a[i][j];
        }
    }
    dp.resize(n);
    for(int i=0; i<n; i++){
        dp[i].resize(a[i].size()+1, 0);
    }

    calc_dp();

    dp2.resize(n);
    for(int i=0; i<n; i++) dp2[i].resize(m+1, -1);
    cout << find_ans(0, m) << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}