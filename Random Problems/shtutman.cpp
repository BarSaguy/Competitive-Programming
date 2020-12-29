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


int32_t main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    for(int i=0; i<n; i++){
        if(a[i] <= 0) a[i] = -2;
    }

    for(int i=0; i<n; i++){
        int x = a[i] - 1;
        while(x >= 0 && x <= n-1){
            int t = a[x];
            a[x] = -1;
            x = t;
        }
    }
    int ans = n+1;
    for(int i=0; i<n; i++){
        if(a[i] != -1){
            ans = i+1;
            break;
        }
    }
    cout << ans << endl;
    

    return 0;
}