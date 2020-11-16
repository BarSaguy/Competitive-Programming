#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main(){
    int t; cin >> t;
    for(int k=0; k<t; k++){
        int n; cin >> n;
        int count = 0;
        stringstream ss;
        string a, b;
        bool revert = false;
        int c1 = 0, c2 = n-1;
        cin >> a >> b;
        for(int i=0; i<n;i++){
            if(!revert){
                if(a[c1] == b[n-1-i]){
                    ss << 1 << " ";
                    count++;
                }
                c1++;
            }
            else{
                if(a[c2] != b[n-1-i]){
                    ss << 1 << " ";
                    count++;
                }
                c2--;
            }

            ss << n-i << " ";
            count++;


            revert = !revert;
        }
        cout << count << " ";
        cout << ss.str() << endl;
    }

    return 0;
}