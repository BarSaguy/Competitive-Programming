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


int n, m, k; 
vi c;
bool can(int steps){
    int diff_cnt = 0;
    int total_cnt = 0;

    vi cnt(m, 0);
    for(int i=0, j=0; i<n; i++){
        total_cnt++;
        cnt[c[i]]++;
        
        while(total_cnt - steps > k && j<i){
            cnt[c[j]]--;
            total_cnt--;
            j++;
        }
        if(cnt[c[i]] >= steps) return true;
    }
    return false;
}

void solve(){
    cin >> n >> m >> k;
    c.resize(n);
    for(int i=0; i<n; i++) {cin >> c[i]; c[i]--;}
    int ans = 0;
    int l=0, r=n+1; 
    while(l < r){
        int m = (l+r)/2;
        if(can(m)){
            ans = m;
            l = m+1;
        }
        else{
            r = m;
        }
    }
    cout << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}