#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& g, vector<bool>& visited, vector<int>& stk, int u) {
	if (visited[u]) {
		return;
	}
	visited[u] = true;
	for (auto v: g[u]) {
		dfs(g, visited, stk, v);
	}
	stk.push_back(u);
}

int main(int argc, char const *argv[]) {
	int n, m;
	for (cin >> n >> m; n != 0 or m != 0; cin >> n >> m) {
		vector<vector<int>> g(n+1);
		vector<vector<int>> gr(n+1);
		for (size_t i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (c == 1) {
				g[a].push_back(b);
				gr[b].push_back(a);
			}
			else {
				g[a].push_back(b);
				g[b].push_back(a);
				gr[a].push_back(b);
				gr[b].push_back(a);
			}
		}
		vector<int> stk;
		vector<int> stk2;
		vector<bool> visited(n+1, false);
		for (int i = 1; i <= n; i++) {
			dfs(g, visited, stk, i);
		}
		visited = vector<bool>(n+1, false);
		int components = 0;
		while (not stk.empty()) {
			int u = stk.back();
			stk.pop_back();
			if (not visited[u]) {
				dfs(gr, visited, stk2, u);
				components++;
			}
		}
		cout << (components == 1) << endl;
	}
	return 0;
}
