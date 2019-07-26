#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	vector<bool> sieve(MAX+1, true);
	vector<int> p;
	sieve[0] = false;
	sieve[1] = false;
	for (int i = 2; i <= MAX; i++) {
		if (sieve[i]) {
			p.push_back(i);
			for (int j = 2*i; j <= MAX; j += i) {
				sieve[j] = false;
			}
		}
	}
	for (cin >> n; n != 0; cin >> n) {
		bool ans = false;
		for (int i = 0; 2*p[i] <= n; i++) {
			if (sieve[n - p[i]]) {
				printf("%d = %d + %d\n", n, p[i], n - p[i]);
				ans = true;
				break;
			}
		}
		if (not ans) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
	return 0;
}
