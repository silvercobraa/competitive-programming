#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		vector<int> factors;
		printf("%d = ", n);
		int x = n;
		if (n < 0) {
			x = -n;
			n = -n;
			factors.push_back(-1);
		}
		if (x != 2147483647 and x != 1) {
			// for (int i = 2; n != 1 and i*i <= n; i++) {
				for (int i = 2; x != 1 and i*i <= n; i++) {
					while (x % i == 0) {
						factors.push_back(i);
						x /= i;
					}
				}
		}
		if (x != 1) {
			factors.push_back(x);
		}
		printf("%d", factors[0]);
		for (int i = 1; i < factors.size(); i++) {
			printf(" x %d", factors[i]);
		}
		puts("");
	}
	return 0;
}
