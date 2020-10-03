#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {
	int ans = 0;
	for ( ; x != 0; x /= 10) {
		ans *= 10;
		ans += x % 10;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	vector<int> sieve(1000000, true);
	for (int p = 2; p < sieve.size(); p++) {
		if (sieve[p]) {
			for (int m = 2*p; m < sieve.size(); m += p) {
				sieve[m] = false;
			}
		}
	}
	while (cin >> n) {
		if (sieve[n]) {
			int rev = reverse(n);
			if (n != rev and sieve[rev]) {
				printf("%d is emirp.\n", n);
			}
			else {
				printf("%d is prime.\n", n);
			}
		}
		else {
			printf("%d is not prime.\n", n);
		}
	}
	return 0;
}
