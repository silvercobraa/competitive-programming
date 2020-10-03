#include <iostream>
#include <vector>

using namespace std;

void distinct_prime_factors(vector<int>& lp, int x) {
	cout << x << " : ";
	vector<int> ans = {1};
	do {
		if (lp[x] != ans.back()) {
			ans.push_back(lp[x]);
		}
		x /= lp[x];
	} while (x != 1);
	// for (auto f: ans) {
	// 	cout << f << " ";
	// }
	// cout << endl;
	cout << ans.size()-1 << endl;
}

int main(int argc, char const *argv[]) {
	int n = 1000000;

	vector<int> lp(n+1);
	for (int i = 0; i <= n; i++) {
		lp[i] = 1;
	}
	vector<int> primes;
	for (int x = 2; x <= n; x++) {
		if (lp[x] == 1) {
			lp[x] = x;
			primes.push_back(x);
		}
		for (int i = 0; i < primes.size() and primes[i] <= lp[x] and primes[i]*x <= n; i++) {
			lp[primes[i]*x] = primes[i];
		}
	}
	// for (auto x: primes) {
	// 	cout << x << endl;
	// }
	for (cin >> n; n != 0; cin >> n) {
		distinct_prime_factors(lp, n);
	}
	return 0;
}
