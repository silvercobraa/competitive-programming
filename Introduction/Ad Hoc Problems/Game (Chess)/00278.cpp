#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		char piece;
		int n, m;
		cin >> piece >> n >> m;
		if (piece == 'r' or piece == 'Q') {
			cout << min(n, m) << endl;
			continue;
		}
		else if (piece == 'K') {
			int rows = n % 2 ? n/2 + 1: n/2;
			int cols = m % 2 ? m/2 + 1: m/2;
			cout << rows*cols << endl;
			continue;
		}
		int ans = 0;
		int rows = n / 2;
		for (size_t i = 0; i < m; i++) {
			if (i % 2 == 0 and n % 2 == 1) {
				ans += rows + 1;
			}
			else {
				ans += rows;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
