#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    int min = a[0], idx = 0;
    for(int i=0; i<n; i++){
        int x = a[i] - b[(i-1 + n)%n];
        if(x < 0)
            x = 0;
        if(i == 0){
            min = a[0] - x;
            idx = 0;
        }
        else if(min>a[i] - x){
            min = a[i] - x;
            idx = i;
        }
        sum += x;
    }
    cout << sum + min<< endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();

    return 0;
}
