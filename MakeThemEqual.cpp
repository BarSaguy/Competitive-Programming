#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>

void solve()
{
    int n; cin >> n;
    vi a(n);
    int sum = 0;
    int count = 0;
    stringstream ss;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n != 0){
        cout << -1 << endl;
        return;
    }
    int num = sum / n;
    for(int i=1; i<n; i++){
        if(a[i] > num && a[i] >= i+1){
            int c = a[i] / (i+1);
            ss << i+1 << " 1 " << c << endl;
            count++;
            a[i] -= c * (i+1);
        }
    }
    for(int i=1; i<n; i++){
        if(a[i] > num && a[i] < i+1){
            ss << "1 " << i+1 << " " << i+1-a[i] << endl;
            ss << i+1 << " 1 " << 1 << endl;
            a[i] = 0;
            count+= 2;
        }  
    }

    for(int i=1; i<n; i++){
        if(a[i] != num){
            ss << "1 " << i+1 << " " << num - a[i] << endl;
            count++;
        }  
    }
    cout << count << endl;
    cout << ss.str();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}