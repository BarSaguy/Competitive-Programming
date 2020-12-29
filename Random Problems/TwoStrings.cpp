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

void solve(){
    string s, t; cin >> s >> t;
    int n=s.size(), m=t.size();
    int cnt = 0;
    for(int i=0, j=0; i<n, j<m; i++){
        if(s[i] == t[j]) {cnt++;j++;}
    }
    if(cnt != m){
        cout << "No" << endl;
        return;
    }
    vi cnt1(26, 0);
    vi cnt2(26, 0);
    for(int i=0;i<n; i++) cnt1[s[i]-'a']++;
    for(int i=0;i<m; i++) cnt2[t[i]-'a']++;
    for(int i=0; i<26; i++){
        if(cnt1[i] && !cnt2[i]){
            cout << "No" << endl;return;
        }
    }
    cout << "Yes" << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}