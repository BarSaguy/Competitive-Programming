#include <bits/stdc++.h> 

using namespace std;
#define int long long


int32_t main(){
	vector<int> a(10);
	for(int i=0; i<10; i++) a[i] = i;
	sort(a.begin(), a.end(), []( const int& lhs, const int& rhs )
		{
			return lhs < rhs;
		});
	for(int i=0; i<10; i++) cout << a[i] << " ";
	return 0;
}
