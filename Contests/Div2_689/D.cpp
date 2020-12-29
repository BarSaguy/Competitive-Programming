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

set<int> sums;
vi a;

int bin_search(int l, int r,int val){
    int ans = r;
    while(l < r){
        int m = (l+r)/2;
        if(a[m] <= val) l = m+1;
        else{
            ans = m;
            r = m;
        }
    }
    return ans;
}
void find_sums(int cur_sum, int l, int r){
    if(l > r) return;
    sums.insert(cur_sum);
    if(l == r){
        return;
    }
    
    int m  = bin_search(l, r+1, (a[l]+a[r])/2);
    if(r - m > m - l+1){
        int rem_sum = 0;
        for(int i=l; i<m; i++){
            rem_sum += a[i];
        }
        if(rem_sum == 0) return;
        find_sums(rem_sum, l, m-1);
        find_sums(cur_sum-rem_sum, m, r);
    }
    else{
        int rem_sum = 0;
        for(int i=m; i<r+1; i++){
            rem_sum += a[i];
        }
        if(rem_sum == 0) return;
        find_sums(cur_sum-rem_sum, l, m-1);
        find_sums(rem_sum, m, r);
    }
}

void solve(){
    int n, q; cin >> n >> q;
    sums.clear();
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(all(a));
    int cs=0; for(int i=0; i<n; i++) cs+=a[i];
    find_sums(cs, 0, n-1);
    for(int i=0; i<q; i++) {
        int s; cin >> s;
        if(sums.find(s) != sums.end()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}