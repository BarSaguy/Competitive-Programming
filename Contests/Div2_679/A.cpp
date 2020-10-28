#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    int a1, a2;
    int b1, b2;
    for(int i=0; i<n; i++){
        if(i%2==0)
            cin >> a1;
        else
        {
            cin >> a2;
            b1 = -a2;
            b2 = a1;
            if(i == n-1)
                cout << b1 << " " << b2 << endl;
            else
                cout << b1 << " " << b2 << " ";
        }
        
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}