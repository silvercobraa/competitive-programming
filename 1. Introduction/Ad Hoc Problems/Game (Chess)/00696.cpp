#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	for (cin >>n >> m; n != 0 or m != 0; cin >> n >> m) {
		int a = n / 2;
		int b = n - a;
		int c = m / 2;
		int d = m - c;
		int ans = b*d + a*c;
		if (n == 1) {
			ans = m;
		}
		else if (m == 1) {
			ans = n;
		}
		else if (n == 2) {
			if (m % 4 == 0) {
				ans = m;
			}
			else if (m % 4 == 1) {
				ans = (m/4)*4 + 2;
			}
			else if (m % 4 == 2) {
				ans = (m/4)*4 + 4;
			}
			else if (m % 4 == 3) {
				ans = (m/4)*4 + 4;
			}
			else {
				ans = (m/4)*4;
			}
		}
		else if (m == 2) {
			if (n % 4 == 0) {
				ans = n;
			}
			else if (n % 4 == 1) {
				ans = (n/4)*4 + 2;
			}
			else if (n % 4 == 2) {
				ans = (n/4)*4 + 4;
			}
			else if (n % 4 == 3) {
				ans = (n/4)*4 + 4;
			}
			else {
				ans = (n/4)*4;
			}
		}
		cout << ans  << " knights may be placed on a " << n << " row " << m << " column board." << endl;
	}
	return 0;
}
