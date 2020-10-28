#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int s1=0, s2=0, s3=0;
    for(int i=0; i<k; i++){
        if(s[i] == '0')
            s1++;
        else if(s[i] == '1')
            s2++;
        else 
            s3++;
    }
    if(abs(s2-s1) > s3){
        cout << "NO" << endl;
        return;
    }
    
    for(int i=k; i<n; i++){
        if(s[i] == '?') s[i] = s[i-k];
        else if(s[i-k] != '?' && s[i] != s[i-k]){cout << "NO" << endl;return;}
        else if(s[i-k] == '?'){
            s3--;
            if(s[i] == '0')
                s1++;
            else
                s2++;
        }
        if(abs(s2-s1) > s3){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}