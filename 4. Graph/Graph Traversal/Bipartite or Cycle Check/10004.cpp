#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& g, vector<int>& color, int u, int c) {
	color[u] = c;
	for (int v : g[u]) {
		if (color[v] == c) {
			return false;
		}
		if (color[v] == 0 and not dfs(g, color, v, 3-c)) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int n, m;
	for (cin >> n >> m; n != 0; cin >> n >> m) {
		vector<vector<int>> g(n);
		vector<int> color(n, 0);
		for (size_t i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		bool ans = dfs(g, color, 0, 1);
		if (ans) {
			cout << "BICOLORABLE." << endl;
		}
		else {
			cout << "NOT BICOLORABLE." << endl;
		}
	}
	return 0;
}
