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

string s;

int calc_val(int l, int r){

}

int calc_val_mul(int l, int r){

}

int calc_val_plus(int l, int r){
    
}

void solve(){
    cin >> s;
    int n = s.length();
    int mul_cnt = 0;
    for(auto c : s){
        if(c == '*')mul_cnt++;
    }
    vvi val(mul_cnt);
    for(int i=0; i<mul_cnt; i++) val[i].resize(2, 0);
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] != '*') continue;
        else{
            val[cnt][0] = calc_val(0, i);
            val[cnt][1] = calc_val(i+1, n);
            cnt++;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}