#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> g;
vector<bool> vis;
vector<int> reach;

int dfs(int u) {
	int count = 0;
	vis[u] = true;
	if (not vis[g[u]]) {
		count = dfs(g[u]) + 1;
	}
	reach[u] = count;
	vis[u] = false;
	return count;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		g = vector<int>(n);
		vis = vector<bool>(n, false);
		reach = vector<int>(n, -1);
		for (size_t i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			g[a-1] = b-1;
		}
		int best = -1;
		int ans = -1;
		for (int i = 0; i < n; i++) {
			if (reach[i] == -1) {
				dfs(i);
			}
			if (reach[i] > best) {
				best = reach[i];
				ans = i;
			}
		}
		cout << "Case " << t+1 << ": " << ans+1 << endl;
	}
	return 0;
}
