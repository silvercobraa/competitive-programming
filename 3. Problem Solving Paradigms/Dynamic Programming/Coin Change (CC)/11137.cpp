#include <iostream>
#include <vector>

using namespace std;

typedef long long Int;

vector<int> c(21+1);
vector<vector<Int>> dp;

Int compute(Int money, Int coin) {
	// cout << money << " " << c[coin] << endl;
	if (coin == 1) {
		// return money+1;
		return 1;
	}
	if (dp[money][coin] != -1) {
		return dp[money][coin];
	}
	dp[money][coin] = 0;
	if (c[coin] <= money) {
		dp[money][coin] += compute(money - c[coin], coin);
	}
	dp[money][coin] += compute(money, coin - 1);
	// printf("dp[%d][%d] = %d\n", money, coin, dp[money][coin]);
	return dp[money][coin];
}

int main(int argc, char const *argv[]) {
	int n;
	for (Int i = 1; i <= 21; i++) {
		c[i] = i*i*i;
		// cout << c[i] << endl;
	}
	while (cin >> n) {
		dp = vector<vector<Int>>(n+1, vector<Int>(21+1, -1));
		Int ans = compute(n, 21);
		cout << ans << endl;
	}
	return 0;
}
