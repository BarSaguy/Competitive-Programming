#include <bits/stdc++.h>


using namespace std;

#define int long long
#define ii pair<int,int>
#define vi vector<int>


int find_x(int a, int max){
    int start = 0, end = 10e18, mid, ans;
    while(start < end){
        mid = (start + end) / 2;
        if(a -3*mid*mid - 3*mid - 1 <= max) ans = mid, start = mid + 1;
        else end = mid;
    }

    return ans;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vi a(n);
    priority_queue<ii> pq; 
    for(int i=0; i<n; i++){
        cin >> a[i];
        pq.emplace(a[i]-3-3-1, i);
    }
    int cnt = 0;
    vi b(n, 0);
    int start = 0, end = 10e9, mid;
    while(start < end){
        mid = (start + end) / 2;
        int sum = 0;
        for(int i=0; i<n;i++){
            int x = find_x(a[i], mid);
            sum += x;
        }
        if(sum < k) start = mid + 1;
        else end = mid;
    }
    while(cnt < k){
        ii top = pq.top();
        pq.pop();
        int i = top.second;
        if(b[i] == a[i])
            continue;
        b[i]++;
        int bi = b[i]+1;
        pq.emplace(a[i]-3*bi*bi-3*bi-1,i);
        cnt++;
    }
    for(int i=0; i<n;i++)
        cout << b[i] << " ";
    

    return 0;
}