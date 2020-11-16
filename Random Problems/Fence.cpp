#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve(){
    ll a,b,c; cin >> a >> b >> c;
    ll d = sqrt(a*a + (c-b)*(c-b)) + 1;
    cout << d << endl;
}

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++)
        solve();

    return 0;
}