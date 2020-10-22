#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
private:
	vector<int> parent;
	vector<int> size;

public:
	DSU (int n) {
		size = vector<int>(n, 1);
		parent = vector<int>(n, 0);
		for (size_t i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int x) {
		return parent[x] == x ? x : find(parent[x]);
	}
	void merge(int a, int b) {
		int x = find(a);
		int y = find(b);
		if (x == y) return;
		if (size[x] <= size[y]) {
			parent[x] = y;
			size[y] += size[x];
		}
		else {
			parent[y] = x;
			size[x] += size[y];
		}
	}
	bool same(int a, int b) {
		return this->find(a) == this->find(b);
	}
};

int main(int argc, char const *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF, n or m) {
		vector<vector<int>> edges(m);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edges[i] = {w, u, v};
		}
		sort(edges.begin(), edges.end());
		DSU dsu(n);
		vector<int> solution;
		for (auto edge: edges) {
			if (dsu.find(edge[1]) != dsu.find(edge[2])) {
				dsu.merge(edge[1], edge[2]);
			}
			else {
				solution.push_back(edge[0]);
			}
		}
		if (solution.empty()) {
			puts("forest");
		}
		else {
			for (int i = 0; i < solution.size(); i++) {
				if (i != 0) cout << " ";
				cout << solution[i];
			}
			cout << endl;
		}
	}
	return 0;
}
