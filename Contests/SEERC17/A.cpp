#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <utility>
#include <iomanip>
using namespace std;

const int MOD = 1e9 + 7;

int k, n;
vector<int> wait(26);
string s, a;
vector<vector<int>> dp;


int help(int x, int y) {
    if(x == k) return 1;
	if(y >= n) return 0;
	if (dp[x][y] != -1) return dp[x][y];

	
	int res = help(x, y + 1);
	if (a[x] == s[y]) {
		res = (res + help(x+1, y + 1 + wait[a[x] - 'A'])) % MOD;
	}
	dp[x][y] = res;
	return res;
}

void solve() {


	cin >> k >> n;
    dp.resize(k, vector<int>(n, -1));

	for(int i = 0; i < 26; i++) {
		cin >> wait[i];
	}
	cin >> a >> s;
	
	// for (int i = 0; i < k; i++) {
	// 	dp[i][n-1] = 0;
	// }
	// for (int i = 0; i < n; i++) {
	// 	dp[k-1][i] = (a[k - 1] == s[i]);
	// }
	help(0, 0);
	cout << dp[0][0] << endl;
}

int32_t main() {
	solve();
	return 0;
}

/* 2 10
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
AB
ABBBBABBBB*/