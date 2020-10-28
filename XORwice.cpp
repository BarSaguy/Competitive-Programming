#include <iostream>
#include <string>

using namespace std;

int main(){
    int t; cin >> t;
    for(int _=0; _<t; _++){
        int a,b; cin >> a >> b;
        int result = 0;
        int i = 1;
        while(a>0 || b > 0){
            
            if(a%2 == 1 && b%2 == 1)
                result += 1*i;
            i *= 2;
            a /=2;
            b /= 2;
        }

        cout << result << "\n";
    }

    return 0;
}