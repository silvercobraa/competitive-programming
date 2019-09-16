#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	vector<int> primes;
	vector<bool> sieve(100, true);
	for (int i = 2; i < 100; i++) {
		if (sieve[i]) {
			primes.push_back(i);
			for (int j = 2*i; j < 100; j += i) {
				sieve[j] = false;
			}
		}
	}
	// for (auto p: primes) {
	// 	cout << p << " ";
	// }
	int n;
	for (cin >> n; n != 0; cin >> n) {
		vector<int> factorization(primes.size(), 0);
		int greatest = 0;
		for (int i = 2; i <= n; i++) {
			int k = i;
			for (int j = 0; j < primes.size() and primes[j] <= n; j++) {
				// cout << j << " ";
				while (k % primes[j] == 0) {
					factorization[j]++;
					k /= primes[j];
					greatest = max(greatest, j);
				}
			}
			// cout << endl;
		}
		printf("%3d! =", n);
		for (int i = 0; i <= greatest; i++) {
			if (i != 0 and i % 15 == 0) {
				printf("\n      ");
			}
			printf("%3d", factorization[i]);
		}
		puts("");
	}
	return 0;
}
