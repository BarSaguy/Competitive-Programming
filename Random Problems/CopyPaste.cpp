#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int min = a[0];
    int idx = 0;
    for(int i=1; i<n; i++)
        if(min > a[i]){
            min = a[i];
            idx = i;
        }
    int sum = 0;
    for(int i=0; i<n;i++){
        if( i == idx )
            continue;
        sum += (k - a[i]) / min;
    }

    cout << sum << endl;

}

int main(){
    int t; cin >> t;
    for(int i=0; i<t;i++){
        solve();
    }
    return 0;
}