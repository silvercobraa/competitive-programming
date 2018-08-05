#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		n -= 2;
		m -= 2;
		int rows = n / 3 + (n % 3 ? 1 : 0);
		int cols = m / 3 + (m % 3 ? 1 : 0);
		cout << rows * cols << endl;
	}
	return 0;
}
