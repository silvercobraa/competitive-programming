#include <iostream>
#include <vector>
#include <cassert>
#define MAX 100

using namespace std;

int main(int argc, char const* argv[])
{
	int N, K;
	for (cin >> N >> K; N != 0 && K != 0; cin >> N >> K) {
		vector<vector<int>> DP(K + 1, vector<int>(N + 1, 0));
		for (int j = 0; j <= N; j++) {
			DP[1][j] = 1;
		}
		for (int i = 1; i <= K; i++) {
			DP[i][0] = 1;
			DP[i][1] = i;
		}
		// cout << N << ' ' << K << endl;
		for (int i = 2; i <= K; i++) {
			for (int j = 2; j <= N; j++) {
				DP[i][j] = 0;
				for (int k = 0; k <= N && j - k >= 0; k++) {
					// printf("%d %d %d %d\n", i, j, k, N - k);
					// cout << i << ' ' << j << ' ' << k << endl;
					// assert(j - k >= 0);
					DP[i][j] += (DP[i - 1][j - k]) % 1000000;
				}
				// cout << DP[i][j] << ' ';

			}
			// cout << endl;
		}
		// cout << DP[K - 1][N - 1] << endl;
		cout << DP[K][N] % 1000000 << endl;
	}
	return 0;
}
