#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
	int n;
	// while (cin >> n) {
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	vector<vector<int>> sum(n, vector<int>(n));
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
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
	int best = -127*100*100 - 1;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			for (size_t i2 = i; i2 < n; i2++) {
				for (size_t j2 = j; j2 < n; j2++) {
					int tmp = sum[i2][j2];
					if (i != 0 and j != 0) {
						// cout << "sumando " << sum[i-1][j-1] << endl;
						tmp += sum[i-1][j-1];
					}
					if (i != 0) {
						// cout << "restando " << sum[i-1][j2] << endl;
						tmp -= sum[i-1][j2];
					}
					if (j != 0) {
						// cout << "restando " << sum[i2][j-1] << endl;
						tmp -= sum[i2][j-1];
					}
					// printf("(%d,%d) (%d,%d): %d\n", i, j, i2, j2, tmp);
					best = max(best, tmp);
				}
			}
		}
	}
	cout << best << endl;
	// }
	return 0;
}
