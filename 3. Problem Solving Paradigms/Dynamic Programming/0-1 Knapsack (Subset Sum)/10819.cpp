#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
vector<int> p;
vector<int> f;

int compute(const int money, int k, int spent) {
	// cout << "spent: " << spent << ", k: " << k << endl;
	if (spent > money + 200) {
		return -1;
	}
	if (k == dp.size()) {
		if (spent <= 2000 and spent > money) {
			return -1;
		}
		if (spent > 2000 and spent > money + 200) {
			return -1;
		}
		// cout << "returning 0" << endl;
		return 0;
	}
	if (dp[k][spent] != -1) {
		return dp[k][spent];
	}
	int ans = -1;
	int rec1  = compute(money, k + 1, spent + p[k]);
	if (rec1 != -1) {
		ans = max(ans, rec1 + f[k]);
		// puts("updating with rec1");
	}
	int rec2  = compute(money, k + 1, spent);
	if (rec2 != -1) {
		ans = max(ans, rec2);
		// puts("updating with rec2");
	}
	// printf("dp[%d][%d] = %d\n", k, spent, dp[k][spent]);
	return dp[k][spent] = ans;
}

int main(int argc, char const *argv[]) {
	int m, n;
	while (cin >> m >> n) {
		// cout << "n: " << n << endl;
		dp = vector<vector<int>>(n, vector<int>(m+200+1, -1));
		p = vector<int>(n);
		f = vector<int>(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i] >> f[i];
		}
		int ans = compute(m, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
