#include <iostream>

using namespace std;

int ans(int n, int bits) {
	int flip = 0;
	int ret = 0;
	for (int i = 0; i < bits; i++, n/=2) {
		ret <<= 1;
		int bit = n & 1;
		if (not flip) {
			// cout << bit;
			ret |= bit;
		}
		else {
			// cout << flip - bit;
			ret |= flip - bit;
		}
		flip = bit;
	}
	// cout << endl;
	return ret;
}

int reverse_bits(int n, int b) {
	int ret = 0;
	for (int i = 0; i < b; i++) {
		ret <<= 1;
		ret |= (n >> (i)) & 1;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, k;
		cin >> n >> k;
		cout << ans(reverse_bits(k, n), n) << endl;
	}
	return 0;
}
