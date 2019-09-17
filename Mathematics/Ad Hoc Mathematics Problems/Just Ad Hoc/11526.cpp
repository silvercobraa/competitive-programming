#include <iostream>

using namespace std;


long long H(int n) {
	long long res = 0;
	for( int i = 1; i <= n; i=i+1 ) {
		res = (res + n/i);
		printf("%3d ", n / i);
		// printf("%3d ", i);
	}
	cout << ": ";
	return res;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t i = 0; i < T; i++) {
		long long n;
		cin >> n;
		// n = i;
		if (n <= 0) {
			cout << 0 << endl;
			continue;
		}
		long long sum = 0;
		long long root = 0;
		for (long long k = 1; k*k <= n; k++) {
		// for (int k = 2; k <= root; k++) {
			// if (k - 1 == n/k) {
			// 	cout << "AAA ";
			// 	sum -= k;
			// }
			if (k == n / k) {
				sum -= k;
			}
			sum += n / k;
			// cout << n/k << " ";
			sum += k * (n/k - n/(k+1));
			// for (int j = 0; j < (n/k - n/(k+1)); j++) {
			// 	cout << k << " ";
			// }
		}
		// cout << H(x) << endl;
		// cout << "-> " << sum << endl;
		cout << sum << endl;
	}
	return 0;
}
