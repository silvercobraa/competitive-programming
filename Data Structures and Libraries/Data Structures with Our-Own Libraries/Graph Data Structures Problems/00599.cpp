#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& graph, vector<bool>& vis, int u) {
	int count = 1;
	vis[u] = true;
	for (int v: graph[u]) {
		if (not vis[v]) {
			count += dfs(graph, vis, v);
		}
	}
	return count;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		string s = "";
		vector<vector<int>> graph(26);
		for (cin >> s; s[0] != '*'; cin >> s) {
			int a = s[1] - 'A';
			int b = s[3] - 'A';
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		vector<bool> visited(26, false);
		cin >> s; // consumir nodos
		int trees = 0;
		int acorns = 0;
		for (int i = 0; i < s.size(); i += 2) {
			int u = s[i] - 'A';
			if (not visited[u]) {
				int nodes = dfs(graph, visited, u);
				if (nodes == 1) {
					acorns++;
				}
				else {
					trees++;
				}
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}
	return 0;
}
