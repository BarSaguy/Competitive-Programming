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

void solve(){
    int n,m; cin >> n >> m;
    vi l(m), r(m), q(m);
    for(int i=0; i<m; i++){
        cin >> l[i] >> r[i] >> q[i];
        l[i]--; r[i]--;
    }

    vvi cnt1(30), cnt2(30);
    for(int i=0; i<30; i++) cnt1[i].resize(n+1, 0);
    for(int i=0; i<30; i++) cnt2[i].resize(n+1, 0);
    vi bits1(30, 0), bits2(30, 0);
    vi values(n, -1);
    vi a(n);

    for(int i=0; i<m; i++){
        values[r[i]] = q[i];
        int idx = 0;
        for(int j=q[i];idx<30 ; j /=2){
            if(j % 2){
                cnt1[idx][l[i]]++;
                cnt1[idx][r[i]+1]--;
            }
            else{
                cnt2[idx][l[i]]++;
                cnt2[idx][r[i]+1]--;
            }
            idx++;
        }
    }

    for(int i=0; i<n; i++){ 
        for(int j=0; j<30; j++){
            bits1[j] += cnt1[j][i];
        }

        for(int j=0; j<30; j++){
            bits2[j] += cnt2[j][i];
        }

        int val_and = 1 << 31 - 1;
        for(int j=29; j>=0; j--){
            val_and = val_and & (bits2[j] << j);
        }
        
        if(values[i] != -1 && values[i] != val_and){
            cout << "NO" << endl;
            return;
        }

        int val_or = 0;
        for(int j=29; j>=0; j--){
            val_or = val_or*2 + (bits1[j]>0);
        }
        a[i] = val_or;
    }
    cout << "YES" << endl;
    for(int i=0; i<n; i++) cout << a[i] << " ";

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    //cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}