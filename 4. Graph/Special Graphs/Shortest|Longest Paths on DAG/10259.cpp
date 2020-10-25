#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> money;
vector<vector<int>> dp;

int compute(int row, int col, int n, int k) {
	if (dp[row][col] != 0) {
		return dp[row][col];
	}
	int ret = money[row][col];
	int best = 0;
	for (int i = max(row-k, 0); i <= min(row+k, n-1); i++) {
		if (i == row or money[i][col] <= money[row][col]) continue;
		best = max(compute(i, col, n, k), best);
	}
	for (int j = max(col-k, 0); j <= min(col+k, n-1); j++) {
		if (j == col or money[row][j] <= money[row][col]) continue;
		best = max(compute(row, j, n, k), best);
	}
	return dp[row][col] = ret + best;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		if (t != 0) cout << endl;
		int n, k;
		cin >> n >> k;
		money = vector<vector<int>>(n, vector<int>(n, 0));
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				cin >> money[i][j];
			}
		}
		dp = vector<vector<int>>(n, vector<int>(n, 0));
		int ans = compute(0, 0, n, k);
		cout << ans << endl;
		money.clear();
		dp.clear();
	}
	return 0;
}
