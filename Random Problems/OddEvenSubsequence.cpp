#include <bits/stdc++.h>

using namespace std;


int n,k; 
vector<int> a;

bool check(int num){
    int cnt = 0, cnt2=0;
    for(int i=0; i<n;i++){
        if(a[i] <= num){
            if(cnt == 0 && i > 0)
                cnt++;
            cnt+=2;
            if(i == n-1)
                cnt--;
            i++;
        }
    }
    if(a[0] <= num){
        for(int i=1; i<n;i++){
            if(a[i] <= num){
                if(cnt2 == 0)
                    cnt2++;
                cnt2+=2;
                if(i == n-1)
                    cnt2--;
                i++;
            }
        }
    }
    if(max(cnt2,cnt) >= k)
        return true;
    return false;
}


int main(){
    cin >> n >> k;
    a.resize(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int start = 1, end = 1e9, mid;
    int lowest = -1;
    while(start < end){
        mid = (start + end) / 2;
        if(check(mid)) lowest = mid, end = mid;
        else start = mid + 1;
    }

   // int max=-1;
   // for(int i=0; i<n;i++){
    //    if(a[i] <= lowest && a[i] > max)
   //         max = a[i];
    //}
  
    cout << lowest << endl;
    return 0;
}