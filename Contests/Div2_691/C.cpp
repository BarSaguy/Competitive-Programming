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


vi fac;
int n,m; 
vi s;


void solve(){
    cin >> n >> m;
    vi a(n);
    vi b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    if(n == 1){
        for(int i=0; i<m; i++){
            cout << b[i] + a[0] << " ";
        }
        return;
    }
    sort(all(a));
    
    s.resize(n-1);
    for(int i=1; i<n; i++) s[i-1] = a[i] - a[i-1];

    int g=s[0];
    for(int i=1; i<n-1; i++){
        g = __gcd(g, s[i]);
    }
    for(int i=0; i<m; i++){
        cout << __gcd(g, b[i]+a[0]) << " ";
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}