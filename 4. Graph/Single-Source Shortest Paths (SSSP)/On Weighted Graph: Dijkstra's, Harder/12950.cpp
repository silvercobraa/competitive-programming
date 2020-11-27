#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<pair<int,int>>> vii;
constexpr int INF = 1000000000;

int dijkstra(vii& graph) {
	priority_queue<pair<int, int>> q;
	vector<bool> visited(graph.size(), false);
	q.push({0, 0});
	visited[0] = true;
	while (not q.empty()) {
		auto top = q.top();
		int dist = top.first;
		int node = top.second;
		q.pop();
		if (node+1 == graph.size()) {
			return -dist;
		}
		visited[node] = true;
		for (auto child: graph[node]) {
			for (auto grandchild: graph[child.second]) {
				if (not visited[grandchild.second]) {
					q.push({dist-child.first-grandchild.first, grandchild.second});
				}
			}
		}
	}
	return -1;
}


int dijkstra2(vii& graph) {
	priority_queue<pair<int, int>> q;
	vector<bool> visited(graph.size(), false);
	q.push({0, 0});
	visited[0] = true;
	while (not q.empty()) {
		auto top = q.top();
		int dist = top.first;
		int node = top.second;
		q.pop();
		if (node+1 == graph.size()) {
			return -dist;
		}
		visited[node] = true;
		for (auto child: graph[node]) {
			if (not visited[child.second]) {
				q.push({dist-child.first, child.second});
			}
		}
	}
	return -1;
}

int dijkstra3(vii& graph) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	vector<int> d(graph.size(), INF);
	d[0] = 0;
	q.push({0, 0});
	while (not q.empty()) {
		auto top = q.top();
		int dist = top.first;
		int node = top.second;
		q.pop();
		if (node+1 == graph.size()) {
			return dist;
		}
		if (dist > d[node]) {
			continue;
		}
		// cout << dist << endl;
		d[node] = dist;
		for (auto child: graph[node]) {
			for (auto grandchild: graph[child.second]) {
				if (dist+child.first+grandchild.first < d[grandchild.second]) {
					q.push({dist+child.first+grandchild.first, grandchild.second});
				}
			}
		}
	}
	return -1;
}


int main(int argc, char const *argv[]) {
	int n, m;
	while (cin >> n >> m) {
		vii graph(n);
		vii graph2(n);
		for (size_t i = 0; i < m; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			graph[a-1].push_back({w, b-1});
			graph[b-1].push_back({w, a-1});
		}
		// for (int i = 0; i < graph.size(); i++) {
		// 	for (int j = 0; j < graph[i].size(); j++) {
		// 		auto e1 = graph[i][j];
		// 		for (int k = 0; k < graph[e1.second].size(); k++) {
		// 			auto e2 = graph[e1.second][k];
		// 			if (i < e2.second) {
		// 				graph2[i].push_back({e1.first+e2.first, e2.second});
		// 				graph2[e2.second].push_back({e1.first+e2.first, i});
		// 			}
		// 		}
		// 	}
		// }

		// cout << dijkstra(graph) << endl;
		// cout << dijkstra2(graph2) << endl;
		cout << dijkstra3(graph) << endl;
	}
	return 0;
}
