#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>


void solve(){
    int n; cin >> n;
    vi b(n);
    vii a(n);
    int ans = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        if(t > ans)
            ans = t;
        a[i] = {t, i};
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    
    for(int i=n-1; i>=0; i--){
        if(sum + b[a[i].second] < ans){
            sum += b[a[i].second];
            if(i > 0){
                if(sum > a[i-1].first){
                    ans = sum;
                    break;
                }
                else
                    ans = a[i-1].first;
            }
            else
            {
                ans = sum;
            }
            
            //ans = max(ans, sum);
        }
        else
        {
            break;
        }
        
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}