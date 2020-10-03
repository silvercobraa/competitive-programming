#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int t = 1; t <= n; t++) {
		int m;
		cin >> m;
		// cout << m << endl;
		long long tax = 0;
		if (m > 1180000) {
			tax += 25LL*(m - 1180000);
			m = 1180000;
			// cout << m << endl;
		}
		if (m > 880000) {
			tax += 20LL*(m - 880000);
			m = 880000;
			// cout << m << endl;
		}
		if (m > 480000) {
			tax += 15LL*(m - 480000);
			m = 480000;
			// cout << m << endl;
		}
		if (m > 180000) {
			tax += 10LL*(m - 180000);
			m = 180000;
			// cout << m << endl;
		}
		tax = (tax + 99)/100;
		if (0 < tax and tax < 2000) {
			tax = 2000;
		}
		printf("Case %d: %ld\n", t, tax);
	}
	return 0;
}
