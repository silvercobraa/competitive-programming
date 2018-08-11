#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1: c1 gana a c2
// 0: c1 empata a c2
// -1: c1 pierde ante c2
int win(char c1, char c2) {
	if (c1 == c2) {
		return 0;
	}
	else if (c1 == 'R' and c2 == 'S') {
		return 1;
	}
	else if (c1 == 'S' and c2 == 'P') {
		return 1;
	}
	else if (c1 == 'P' and c2 == 'R') {
		return 1;
	}
	else {
		return -1;
	}
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int n, m, d;
		cin >> n >> m >> d;
		vector<string> v(n);
		for (size_t i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int k = 0; k < d; k++) {
			vector<string> vv = v;
			for (size_t i = 0; i < n; i++) {
				for (size_t j = 0; j < m; j++) {
					if (i > 0) {
						int res = win(v[i][j], v[i - 1][j]);
						if (res == -1) {
							vv[i][j] = v[i - 1][j];
						}
					}
					if (i + 1 < n) {
						int res = win(v[i][j], v[i + 1][j]);
						if (res == -1) {
							vv[i][j] = v[i + 1][j];
						}
					}
					if (j > 0) {
						int res = win(v[i][j], v[i][j - 1]);
						if (res == -1) {
							vv[i][j] = v[i][j - 1];
						}
					}
					if (j + 1 < m) {
						int res = win(v[i][j], v[i][j + 1]);
						if (res == -1) {
							vv[i][j] = v[i][j + 1];
						}
					}
				}
			}
			v = vv;
		}
		for (size_t i = 0; i < n; i++) {
			cout << v[i] << endl;
		}
	}
	return 0;
}
