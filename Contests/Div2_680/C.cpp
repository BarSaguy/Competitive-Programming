#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vi a;
int maxi;
int big;

void trial_division(int n) {
    int e =n;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            a[d] *= d;
            n /= d;
            if(maxi < d)
                maxi = d;
        }
    }
    if (n > 1)
        big = n;
}

void solve(){
    int p, q; cin >> p >> q;
    if(p < q || p%q != 0){
        cout << p << endl;
        return;
    }
    fill(a.begin(), a.end(), 1);
    maxi = 1;
    big = 1;
    trial_division(q);
    int min=1e18;
    int t = p;
    for(int i=2; i<=maxi; i++){
        if(a[i] != 1){
            int c = 1;
            while(p%a[i] == 0){
                p /= i;
                c *= i;
            }
            if(min > c)
                min = c;          
        }
    }
    if(big > 1){
        int c = 1;
        while(p%big == 0){
            p/=big;
            c*=big;
        }
        if(min > c)
            min = c;
    }

    cout << t / min << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    a.resize(32000);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}