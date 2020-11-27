#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> paths;

int dfs(int u) {
	if (paths[u] != 0) return paths[u];
	if (graph[u].empty()) return paths[u] = 1;
	int count = 0;
	for (auto v: graph[u]) {
		count += dfs(v);
	}
	return paths[u] = count;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		graph.resize(n);
		paths.resize(n, 0);
		for (size_t i = 0; i < m; i++) {
			char a, b;
			cin >> a >> b;
			graph[a - 'A'].push_back(b - 'A');
		}
		for (int i = 0; i < n; i++) {
			sort(graph[i].begin(), graph[i].end());
			graph[i].erase(unique(graph[i].begin(), graph[i].end() ), graph[i].end());
		}
		for (size_t i = 0; i < n; i++) {
			dfs(i);
		}
		int q;
		cin >> q;
		string s;
		for (size_t i = 0; i < q; i++) {
			cin >> s;
			int count = 1;
			int u = s[0] - 'A';
			for (size_t j = 1; j < s.size(); j++) {
				int v = s[j] - 'A';
				for (auto child: graph[u]) {
					if (child == v) {
						break;
					}
					count += paths[child];
				}
				u = v;
			}
			cout << s << ": " << count << endl;
		}
		graph.clear();
		paths.clear();
	}
	return 0;
}
