#include <iostream>
#include <vector>
#include <set>

#define INF 99999999

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		std::vector<std::vector<int>> dist(n, vector<int>(m, INF));
		std::vector<std::vector<int>> cost(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> cost[i][j];
			}
		}
		set<pair<int, int>> pq;
		dist[0][0] = cost[0][0];
		pq.insert({dist[0][0], 0});
		while (not pq.empty()) {
			// cout << pq.size() << endl;
			pair<int, int> p = *pq.begin();
			// cout << p.second << endl;
			int row = p.second / m;
			int col = p.second % m;
			// cout << row << " " << col << endl;
			dist[row][col] = p.first;
			pq.erase(pq.begin());
			if (row != 0 and dist[row-1][col] == INF) {
				pq.insert({dist[row][col] + cost[row-1][col], p.second-m});
			}
			if (row+1 != n and dist[row+1][col] == INF) {
				pq.insert({dist[row][col] + cost[row+1][col], p.second+m});
			}
			if (col != 0 and dist[row][col-1] == INF) {
				pq.insert({dist[row][col] + cost[row][col-1], p.second-1});
			}
			if (col+1 != m and dist[row][col+1] == INF) {
				pq.insert({dist[row][col] + cost[row][col+1], p.second+1});
			}
			if (row+1 == n and col+1 == m) {
				cout << dist[row][col] << endl;
				break;
			}
		}
	}
	return 0;
}
