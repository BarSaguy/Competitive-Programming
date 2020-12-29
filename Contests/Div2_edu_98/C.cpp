#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>

const int INF = 1e18;


void solve(){
    string s; cin >> s;
    int a1 =0, a2=0;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(') a1++;
        else if(s[i] == '[') a2++;
        else if(s[i] == ')' && a1 > 0){a1--;ans++;}
        else if(s[i] == ']' && a2 > 0){a2--;ans++;}
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}