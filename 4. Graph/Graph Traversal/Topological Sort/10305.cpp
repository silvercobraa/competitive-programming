#include <iostream>
#include <vector>

using namespace std;

void toposort(vector<vector<int>>& g, vector<int>& ans, vector<bool>& vis, int u) {
	if (vis[u]) {
		return;
	}
	vis[u] = true;
	for (auto v: g[u]) {
		toposort(g, ans, vis, v);
	}
	ans.push_back(u);
}

int main(int argc, char const *argv[]) {
	int n, m;
	for (cin >> n >> m; n != 0 or m != 0; cin >> n >> m) {
		vector<vector<int>> g(n+1);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			g[0].push_back(i);
		}
		vector<bool> visited(n+1);
		vector<int> pos;
		toposort(g, pos, visited, 0);
		// for (int i = 0; i <= n; i++) {
		// 	toposort(g, pos, visited, i);
		// }
		pos.pop_back();
		for ( ; not pos.empty(); pos.pop_back()) {
			cout << pos.back() << " ";
		}
		cout << endl;
	}
	return 0;
}
