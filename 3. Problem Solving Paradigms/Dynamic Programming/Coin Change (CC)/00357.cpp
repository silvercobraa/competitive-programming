#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	vector<int> coins = {1, 5, 10, 25, 50};
	int MMAX = 30000;
	std::vector<std::vector<long long>> dp(coins.size()+1, vector<long long>(MMAX+1, 1));
	for (int i = 1; i < coins.size(); i++) {
		for (int j = 1; j <= MMAX; j++) {
			if (coins[i] <= j) {
				dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	while (cin >> n) {
		long long ans = dp[coins.size()-1][n];
		if (ans == 1) {
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		}
		else {
			cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;
		}
	}
	// for (int i = 0; i < MMAX; i++) {
	// 	cout << i << " " << dp[coins.size()-1][i] << endl;
	// }
	return 0;
}
