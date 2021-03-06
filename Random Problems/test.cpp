#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#define int int64_t
const int MOD = 998244353;
 
int n, m;
bool zero = false;
std::vector<bool> visited;
std::vector<int> color;
std::vector<std::vector<int>> g;
std::set<int> red;
std::set<int> blue;
 
 
 
int pow(int base, int exp) {
	if (!exp) return 1;
	int res = pow(base, exp / 2);
	int r = (res * res) % MOD;
	if (exp % 2) r = (r * base) % MOD;
	return r;
}
 
void dfs(int u) {
	if (visited[u]) return;
	visited[u] = true;
	for (auto nei : g[u]) {
		if (!visited[nei] && color[nei] == -1) {
			if (color[u]) {
				blue.insert(nei);
				color[nei] = 0;
			}
			else {
				red.insert(nei);
				color[nei] = 1;
			}
		}
	}
	for (auto nei : g[u]) {
		if (color[nei] == color[u]) zero = true;
	}
	for (auto nei : g[u]) dfs(nei);
}
 
 
void solve() {
	int final = 1;
	std::cin >> n >> m;
	color.resize(n, -1);
 
	g.resize(n);
	visited.resize(n, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		--v; --u;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			color[i] = 1;
			red.insert(i);
			dfs(i);
			if (zero) {
				std::cout << 0 << std::endl;
				zero = false;
				return;
			}
			int res1 = pow(2, red.size());
			int res2 = pow(2, blue.size());
			final = (final *((res1 + res2) % MOD)) % MOD;
			red.clear();
			blue.clear();
		}
	}
	std::cout << final << std::endl;
}
 
int32_t main() {
	int t;
	std::cin >> t;
	while (t--) {
		color.clear();
		g.clear();
		visited.clear();
		red.clear();
		blue.clear();
		solve();
	}
	return 0;
}