#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m, n;
vector<string> grid;
vector<vector<int>> visited;
vector<pair<int, int>> delta = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


int dfs(int x, int y, char c) {
	if (x < 0 or x >= m or visited[x][y] or grid[x][y] != c) {
		return 0;
	}
	int count = 1;
	visited[x][y] = true;
	for (auto dir: delta) {
		count += dfs(x + dir.first, (y + n + dir.second) % n, c);
	}
	return count;
}

int main(int argc, char const *argv[]) {
	while (cin >> m >> n) {
		// cout << n << m << endl;
		grid = vector<string>(m);
		visited = vector<vector<int>>(m, vector<int>(n, false));
		for (size_t i = 0; i < m; i++) {
			cin >> grid[i];
		}
		int x, y;
		cin >> x >> y;
		dfs(x, y, grid[x][y]);
		int best = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				best = max(best, dfs(i, j, grid[x][y]));
			}
		}
		cout << best << endl;
	}
	return 0;
}
