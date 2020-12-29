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
int n;
int x, y; 

map<tuple<int,int,int>, int> m;

int cnt = 0;

int dp_f(int i, int ones, int zeros){
    if(i >= n) return 0;
    auto val = m.find({ones,zeros, i});
    if(val != m.end()){
        return val->second;
    }
    cnt++;
    int ans = 0;
    if(s[i] == '0'){
        ans= ones*y + dp_f(i+1, ones, zeros+1);
    }
    else if(s[i] == '1'){
        ans= zeros*x + dp_f(i+1, ones+1, zeros);
    }
    else{
        int a=INF, b=INF;
        if(zeros*x - ones*y <= (n-i)*x)
            a = dp_f(i+1, ones+1, zeros);
        if(ones*y - zeros*x <= (n-i)*y)
            b = dp_f(i+1, ones, zeros+1);
        ans= min(zeros*x +  a, ones*y + b);
    }
    m[{ones,zeros, i}] = ans;
    return ans;
}


void solve(){
    cin >> s;
    n = s.length();
    cin >> x >> y;
  
    cout << dp_f(0, 0, 0) << endl;
    cout << cnt << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}