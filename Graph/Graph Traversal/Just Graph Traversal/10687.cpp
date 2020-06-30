#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = (40*40 + 1)*(40*40 + 1);

int dist(pair<int, int> p1, pair<int, int> p2) {
	int dx = (p1.first - p2.first);
	int dy = (p1.second - p2.second);
	return dx*dx + dy*dy;
}

void dfs(vector<vector<int>>& g, int u, vector<int>& vis) {
	vis[u] = true;
	for (auto v: g[u]) {
		if (not vis[v]) {
			dfs(g, v, vis);
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		vector<pair<pair<int, int>, int>> v(n);
		for (size_t i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v[i] = {{x, y}, i};
		}
		sort(v.begin(), v.end());
		vector<vector<int>> g(n);
		for (int i = 0; i < v.size(); i++) {
			// cout << i << endl;
			// al cuadrado porque no calculo la raiz cuadrada en dist
			int minimum = INF;
			int closest = -1;
			for (int j = 0; j < v.size(); j++) {
				if (j == i) continue;
				int d = dist(v[i].first, v[j].first);
				if (d < minimum) {
					minimum = d;
					closest = j;
				}
			}
			minimum = INF;
			int second_closest = -1;
			for (int j = 0; j < v.size(); j++) {
				if (j == i or j == closest) continue;
				int d = dist(v[i].first, v[j].first);
				if (d < minimum) {
					minimum = d;
					second_closest = j;
				}
			}
			// cout << "closest: " << i << " " << closest << endl;
			// cout << "2closest: " << i << " " << second_closest << endl;
			g[i].push_back(closest);
			g[i].push_back(second_closest);
			// printf("%d -> %d %d\n", i, closest, second_closest);
			// printf("(%d,%d) (%d,%d)\n", v[i].first, v[i].second, v[closest].first, v[closest].second);
		}
		// puts("");
		int start = -1;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].second == 0) {
				start = i;
			}
		}
		// cout << start << endl;
		vector<int> visited(n, false);
		dfs(g, start, visited);
		bool all_visited = true;
		for (auto vis: visited) {
			if (not vis) {
				all_visited = false;
				break;
			}
		}
		if (all_visited) {
			puts("All stations are reachable.");
		}
		else {
			puts("There are stations that are unreachable.");
		}
	}
	return 0;
}
