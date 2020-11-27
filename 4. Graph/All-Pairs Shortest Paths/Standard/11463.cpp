#include <iostream>
#include <vector>

constexpr int INF = 99999999;

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> dist(N, vector<int>(N, INF));
		for (size_t i = 0; i < N; i++) {
			dist[i][i] = 0;
		}
		for (size_t i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			dist[u][v] = 1;
			dist[v][u] = 1;
		}
		for (size_t w = 0; w < N; w++) {
			for (size_t u = 0; u < N; u++) {
				for (size_t v = 0; v < N; v++) {
					dist[u][v] = min(dist[u][v], dist[u][w]+dist[w][v]);
				}
			}
		}
		int s, d;
		cin >> s >> d;
		int ans = 0;
		for (size_t x = 0; x < N; x++) {
			int curr_dist = dist[s][x] + dist[x][d];
			ans = max(ans, curr_dist);
		}
		printf("Case %d: %d\n", t+1, ans);
	}
	return 0;
}
