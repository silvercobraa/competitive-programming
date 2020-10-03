#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> v(n, vector<int>(m));
		vector<vector<int>> sum(n, vector<int>(m));
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				cin >> v[i][j];
				sum[i][j] = v[i][j];
				if (i != 0 and j != 0) {
					sum[i][j] -= sum[i-1][j-1];
				}
				if (i != 0) {
					sum[i][j] += sum[i-1][j];
				}
				if (j != 0) {
					sum[i][j] += sum[i][j-1];
				}
				// printf("%3d ", sum[i][j]);
			}
			// cout << endl;
		}
		int cost = 99999999;
		int area = -1;
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				for (size_t i2 = i; i2 < n; i2++) {
					for (size_t j2 = j; j2 < m; j2++) {
						int new_cost = sum[i2][j2];
						if (i != 0 and j != 0) {
							new_cost += sum[i-1][j-1];
						}
						if (i != 0) {
							new_cost -= sum[i-1][j2];
						}
						if (j != 0) {
							new_cost -= sum[i2][j-1];
						}
						int new_area = (i2-i+1)*(j2-j+1);
						// cout << new_cost << endl;
						if (new_area > area and new_cost <= k or new_area == area and new_cost < cost) {
							area = new_area;
							cost = new_cost;
						}
					}
				}
			}
		}
		if (area == -1) {
			printf("Case #%d: %d %d\n", t+1, 0, 0);
		}
		else {
			printf("Case #%d: %d %d\n", t+1, area, cost);
		}
	}
	return 0;
}
