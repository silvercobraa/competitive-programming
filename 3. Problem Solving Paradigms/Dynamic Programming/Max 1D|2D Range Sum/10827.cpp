#include <iostream>
#include <vector>

constexpr int INF = 99999999;

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int N;
		cin >> N;
		vector<vector<int>> M(2*N, vector<int>(2*N, 0));
		for (size_t i = 0; i < N; i++) {
			for (size_t j = 0; j < N; j++) {
				cin >> M[i][j];
				M[i][j+N] = M[i][j];
				M[i+N][j] = M[i][j];
				M[i+N][j+N] = M[i][j];
			}
		}
		for (int i = 0; i < 2*N; i++) {
			for (int j = 0; j < 2*N; j++) {
				if (i != 0) {
					M[i][j] += M[i-1][j];
				}
				if (j != 0) {
					M[i][j] += M[i][j-1];
				}
				if (i != 0 and j != 0) {
					M[i][j] -= M[i-1][j-1];
				}
				// cout << M[i][j] << " ";
			}
			// cout << endl;
		}
		// cout << endl;
		int best = -INF;
		for (int row1 = 0; row1 < N; row1++) {
			for (int col1 = 0; col1 < N; col1++) {
				for (int row2 = row1; row2 < row1+N; row2++) {
					for (int col2 = col1; col2 < col1+N; col2++) {
						// printf("(%d, %d) (%d, %d)\n", row1, col1, row2, col2);
						int sum = M[row2][col2];
						if (row1 != 0) {
							sum -= M[row1-1][col2];
						}
						if (col1 != 0) {
							sum -= M[row2][col1-1];
						}
						if (row1 != 0 and col1 != 0) {
							sum += M[row1-1][col1-1];
						}
						best = max(best, sum);
					}
				}
			}
		}
		cout << best << endl;

	}
	return 0;
}
