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
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, s, n) for (int i = (s); i < (n); i++)
#define repr(...) GET_MACRO(__VA_ARGS__, repr3, repr2, repr1)(__VA_ARGS__)
#define repr1(n) for (int i = (n)-1; i >= 0; i--)
#define repr2(i, n) for (int i = (n)-1; i >= 0; i--)
#define repr3(i, n, s) for (int i = (n)-1; i >= (s); i--)
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)

const int INF = 1e18;

void solve(){
    int n; cin >> n;
    int l=0, r=n-1;
    int cand = -1;
    cout << "? " << l+1 << " " << r+1 << endl;
    cin >> cand; cand--;
    while(r-l > 1){
        int m = (l+r)/2;
        //if(cand == -1){
       // }
       if(cand >= l && cand <= r){
            if(cand > m){
                cout << "? " << m+1 << " " << r+1 << endl;
                int idx2; cin >> idx2;idx2--;
                if(cand != idx2){
                    r = m-1;
                }else{
                    l = m;
                }

            }
            else
            {
            cout << "? " << l+1 << " " << m+1 << endl;
                int idx2; cin >> idx2;idx2--;
                if(cand != idx2){
                    l = m+1;
                }else{
                    r = m;
                }
            }
        }
        else{
            if(cand > r){
                cout << "? " << m+1 << " " << cand+1 << endl;
                int idx2; cin >> idx2;idx2--;
                if(cand != idx2){
                    r = m-1;
                }else{
                    l = m;
                }

            }
            else
            {
                cout << "? " << cand+1 << " " << m+1 << endl;
                int idx2; cin >> idx2;idx2--;
                if(cand != idx2){
                    l = m+1;
                }else{
                    r = m;
                }
            }
        }
        
    }
    int ans = l+1;
    if(l != r){
        cout << "? " << l+1 << " " << r+1 << endl;
        cin >> cand;
        if(cand == l+1) ans = r+1;
        else ans = l+1;
    }
    cout << "! " << ans << endl;
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}