#include <iostream>
#include <vector>

using namespace std;

// #define NMAX 2000000
//
// vector<bool> prime(NMAX+1, true);
// vector<vector<int>> factors(NMAX+1);
//
// void sieve() {
// 	for (int p = 2; p <= NMAX; p++) {
// 		if (prime[p]) {
// 			for (int j = 2*p; j <= NMAX; j+=p) {
// 				prime[j] = false;
// 				factors[j].push_back(p);
// 			}
// 		}
// 	}
// }
//
// void print(vector<int>& ans, int n) {
// 	if (n == 1) {
// 		if (ans.size() > 1) {
// 			cout << ans[0];
// 			for (int i = 1; i < ans.size(); i++) {
// 				cout << " " << ans[i];
// 			}
// 			cout << endl;
// 		}
// 		return;
// 	}
// 	for (auto f: factors[n]) {
// 		if (ans.empty() or f >= ans.back()) {
// 			ans.push_back(f);
// 			print(ans, n/f);
// 			ans.pop_back();
// 		}
// 		if (ans.empty() or n/f >= ans.back()) {
// 			ans.push_back(n/f);
// 			print(ans, f);
// 			ans.pop_back();
// 		}
// 	}
// 	if (ans.empty() or n >= ans.back()) {
// 		ans.push_back(n);
// 		print(ans, 1);
// 		ans.pop_back();
// 	}
// }

int print2(vector<int>& ans, int n, int k, bool print) {
	if (n == 1) {
		if (ans.size() > 1) {
			if (print) {
				cout << ans[0];
				for (int i = 1; i < ans.size(); i++) {
					cout << " " << ans[i];
				}
				cout << endl;
			}
			return 1;
		}
		return 0;
	}
	int total = 0;
	for (int i = k; i <= n; i++) {
		if (n % i == 0) {
			ans.push_back(i);
			total += print2(ans, n/i, i, print);
			ans.pop_back();
		}
	}
	return total;
}

int main(int argc, char const *argv[]) {
	// sieve();
	// for (int i = 0; i < 20; i++) {
	// 	cout << i << ":";
	// 	for (auto f: factors[i]) {
	// 		cout << " " << f;
	// 	}
	// 	cout << endl;
	// }
	int n;
	for (cin >> n; n != 0; cin >> n) {
		vector<int> ans;
		// print(ans, n);
		cout << print2(ans, n, 2, false) << endl;
		print2(ans, n, 2, true);
		// cout << "-" << endl;
	}
	return 0;
}
