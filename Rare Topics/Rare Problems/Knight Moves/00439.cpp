#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

bool valid(int x, int y) {
	return 0 <= x and x < 8 and 0 <= y and y < 8;
}

int idx(int x, int y) {
	return 8*x + y;
}

int main(int argc, char const *argv[]) {
	vector<vector<int>> g(64);
	vector<vector<int>> dist(64, vector<int>(64, INF));
	for (int i = 0; i < 64; i++) {
		dist[i][i] = 0;
	}
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			for (int dx = -2; dx <= 2; dx++) {
				for (int dy = -2; dy <= 2; dy++) {
					if (valid(x+dx, y+dy) and abs(dx)+abs(dy) == 3) {
						g[idx(x, y)].push_back(idx(x+dx, y+dy));
						// printf("%d %d -> %d %d\n", x, y, x+dx, y+dy);
						dist[idx(x, y)][idx(x+dx, y+dy)] = 1;
					}
				}
			}
		}
	}
	for (int k = 0; k < 64; k++) {
		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 64; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	// for (int i = 0; i < 64; i++) {
	// 	for (int j = 0; j < 64; j++) {
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	string p1, p2;
	while (cin >> p1 >> p2) {
		int pi = idx(p1[0]-'a', p1[1]-'1');
		int pf = idx(p2[0]-'a', p2[1]-'1');
		// cout << pi << " " << pf << endl;
		int ans = dist[pi][pf];
		cout << "To get from " << p1 << " to " << p2 << " takes " << ans << " knight moves." << endl;
	}
	return 0;
}
