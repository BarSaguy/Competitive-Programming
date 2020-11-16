#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        vector<int> a, b;
        int input;
        int n, m; cin >> n >> m;
        for(int j=0; j <n; j++){
            cin >> input;
            a.push_back(input);
        }
        for(int j=0; j <m; j++){
            cin >> input;
            b.push_back(input);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int k = 0, p = 0;
        bool found = false;
        while(k < n && p < m){
            if(a[k] == b[p]){
                cout << "YES" << endl;
                cout << 1 << " " << a[k] << endl; 
                found = true;
                break;
            }
            else if(a[k] < b[p])
                k++;
            else
                p++;
        }
        if(!found)
            cout << "NO" << endl;

    }

    return 0;
}