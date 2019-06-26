#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<pair<int, int>> bridges;
// vector<pair<int, int>> bridges;
int timer = 0;

void dfs(vector<vector<int>>& g, vector<bool>& visited, vector<int>& tin, vector<int>& low, int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(g, visited, tin, low, to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
				// cout << v << " " << to << endl;
				if (v > to) {
					bridges.insert({to, v});
				}
				else {
					bridges.insert({v, to});
				}
				// bridges.push_back({v, to});
			}
        }
    }
}

int main(int argc, char const *argv[]) {
	int n;
	while (cin >> n) {
		vector<vector<int>> g(n);
		vector<bool> visited(n, false);
		vector<int> tin(n, -1);
		vector<int> low(n, -1);
		char c;
		for (int i = 0; i < n; i++) {
			int a;
			int m;
			cin >> a >> c >> m >> c;
			for (int j = 0; j < m; j++) {
				int b;
				cin >> b;
				g[a].push_back(b);
				g[b].push_back(a);
			}
		}
		for (int i = 0; i < n; i++) {
			dfs(g, visited, tin, low, i);
		}
		cout << bridges.size() << " critical links" << endl;
		for (auto p: bridges) {
			cout << p.first << " - " << p.second << endl;
		}
		cout << endl;
		bridges.clear();
		timer = 0;
	}
	return 0;
}
