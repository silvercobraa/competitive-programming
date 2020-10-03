#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

class UF {
private:
	vector<int> parent;
	vector<int> size;

public:
	UF (int n) {
		parent = vector<int>(n);
		size = vector<int>(n);
		for (size_t i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	int find(int x) {
		return parent[x] = parent[x] == x ? x : find(parent[x]);
	}
	void merge(int x, int y) {
		int px = find(x);
		int py = find(y);
		if (size[px] > size[py]) {
			parent[py] = px;
			size[px] += size[py];
		}
		else {
			parent[px] = py;
			size[py] += size[px];
		}
	}
};

int dfs(vector<vector<pair<int,int>>>& tree, int parent, int weight, int node) {
	if (node == 1) {
		// cout << weight << endl;
		return weight;
	}
	for (auto par: tree[node]) {
		if (par.second != parent) {
			int rec = dfs(tree, node, par.first, par.second);
			if (rec != 0) {
				// cout << par.first << endl;
				return max(weight, rec);
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	int n;
	int scenario = 1;
	for (cin >> n; n != 0; cin >> n) {
		vector<pair<int, int>> V(n);
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			V[i] = {a, b};
		}
		set<pair<int, pair<int,int>>> E;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				int dx = V[i].first - V[j].first;
				int dy = V[i].second - V[j].second;
				int dist = dx*dx + dy*dy;
				E.insert({dist, {i, j}});
			}
		}
		UF uf(n);
		vector<vector<pair<int,int>>> tree(n);
		while (not E.empty()) {
			auto e = E.begin();
			int w = e->first;
			int a = e->second.first;
			int b = e->second.second;
			if (uf.find(a) != uf.find(b)) {
				tree[a].push_back({w, b});
				tree[b].push_back({w, a});
				uf.merge(uf.find(a), uf.find(b));
			}
			E.erase(e);
		}
		int ans = dfs(tree, -1, 0, 0);
		// cout << "ANS:" << ans << endl;
		printf("Scenario #%d\n", scenario);
		printf("Frog Distance = %.3lf\n\n", sqrt(ans));
		scenario++;
	}
	return 0;
}
