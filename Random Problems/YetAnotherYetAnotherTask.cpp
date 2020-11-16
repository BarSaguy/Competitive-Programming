#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>



int main(){
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vi a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int max_sum = 0, current_sum = 0;
    for(int i=1; i<=30; i++){
        current_sum = 0;
        for(int j=0; j<n; j++){
            current_sum += a[j];
            if(current_sum < 0 || a[j] > i)
                current_sum = 0;
            if(current_sum - i > max_sum)
                max_sum = current_sum - i;
        }
    }
    cout << max_sum << endl;
    

    return 0;
}
