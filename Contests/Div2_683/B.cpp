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
    int n, m; cin >> n >> m;
    int a;
    int s = 0;
    int count = 0;
    int min = 101;
    int zero = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a;
            if(a == 0)
                zero = 1;
            if(a < 0){
                a = -a;
                count++;
            }
            s += a;
            if(min > a)
                min = a;
        }
    }
    if(count%2==1 && zero == 0){
        s -= 2*min;
    }
    cout << s << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}