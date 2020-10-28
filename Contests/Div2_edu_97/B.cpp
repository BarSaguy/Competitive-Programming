#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            if(s[i] == '0')
                cnt1++;
            else
            {
                cnt2++;
            }
            
        }
    }

    cout << max(cnt1,cnt2) << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}