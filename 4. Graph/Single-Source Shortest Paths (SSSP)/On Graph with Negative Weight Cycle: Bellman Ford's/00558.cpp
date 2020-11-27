#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char const* argv[])
{
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int,int>>> g(n);
		for (int i = 0; i < m; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			g[a].push_back({b, w});
			// cout << a << ' ' << b << ' ' << w << endl;
		}

		vector<int> dist(n, 1e9);
		dist[0] = 0;
		for(int i = 0; i < n - 1; i++) {
			for (int u = 0; u < n; u++) {
				for (auto p : g[u]) {
					int v = p.first, w = p.second;
					dist[v] = min(dist[v], dist[u] + w);
				}
			}
		}
 		bool hayCicloNegativo = false;
		for (int u = 0; u < n; u++) {
			for (auto p: g[u]) {
				int v = p.first, w = p.second;
				if (dist[v] > dist[u] + w) {
					hayCicloNegativo = true;
				}
			}
		}
		if (hayCicloNegativo) {
			cout << "possible" << endl;
		}
		else {
			cout << "not possible" << endl;
		}
	}
	return 0;
}
