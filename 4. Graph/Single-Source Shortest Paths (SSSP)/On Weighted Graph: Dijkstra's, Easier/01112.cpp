#include <iostream>
#include <vector>
#include <set>

using namespace std;

constexpr int INF = 1000000000;

typedef vector<vector<pair<int, int>>> Graph;

void dijkstra(Graph& graph, int start, int T) {
	vector<int> dist(graph.size()+1, INF);
	dist[start] = 0;
	set<pair<int, int>> Q;
	Q.insert({0, start});
	while (not Q.empty()) {
		// cout << "size: " << Q.size() << endl;
		auto parent = Q.begin();
		Q.erase(Q.begin());
		for (auto child: graph[parent->second]) {
			// cout << "child: " << child.second << endl;
			// cout << "new_dist: " << new_dist << endl;
			if (dist[parent->second]+child.first < dist[child.second]) {
				dist[child.second] = dist[parent->second] + child.first;
				Q.insert({dist[child.second], child.second});
			}
		}
	}
	int ans = 0;
	for (size_t i = 1; i < dist.size(); i++) {
		ans += dist[i] <= T;
	}
	// resto 1 porque en el nodo EXIT no hay ratón
	cout << ans << endl;
}

void floyd_warshall(vector<vector<int>>& dist) {
	for (size_t k = 0; k < dist.size(); k++) {
		for (size_t i = 0; i < dist.size(); i++) {
			for (size_t j = 0; j < dist.size(); j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int cases;
	cin >> cases;
	for (size_t t = 0; t < cases; t++) {
		if (t != 0) {
			cout << endl;
		}
		int N, E, T, M;
		cin >> N >> E >> T >> M;
		// Graph graph(N+1);
		vector<vector<int>> dist(N+1, vector<int>(N+1, INF));
		for (size_t i = 0; i < N+1; i++) {
			dist[i][i] = 0;
		}
		// vector<vector<int>> graph(N+1, vector<int>);
		for (size_t i = 0; i < M; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			// cout << a << " " << b << " " << w << endl;
			// graph[b].push_back({w, a});
			dist[a][b] = w;
		}
		// dijkstra(graph, E, T);
		floyd_warshall(dist);
		int ans = 0;
		for (int i = 1; i < dist.size(); i++) {
			ans += dist[i][E] <= T;
		}
		cout << ans << endl;
	}
	return 0;
}
