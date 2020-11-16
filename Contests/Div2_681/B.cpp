#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int a, b; cin >> a >> b;
    string s; cin >> s;
    int ans = 0, dis = 1e18;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '1'){
            if(i == 0 || s[i-1] == '0'){
                if(dis < a)
                    ans += dis;
                else
                {
                    ans += a;
                }
                dis = 0;
            }
        }
        else
        {
            if(ans == 0) continue;
            dis += b;
        }
        
    }

    cout << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}