#include <iostream>
#include <vector>

using namespace std;

typedef long long tipo;

bool symmetric(vector<vector<tipo>>& m) {
	int n = m.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// cout << i << " " << j << endl;
			// cout << n - i - 1 << " " << n - j - 1 << endl;
			if (m[i][j] < 0 or m[i][j] != m[n - i - 1][n - j - 1]) {
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		char c;
		cin >> c;
		cin >> c;
		int n;
		cin >> n;
		vector<vector<tipo>> m(n, vector<tipo>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
			}
		}
		cout << "Test #" << t << ": ";
		if (symmetric(m)) {
			cout << "Symmetric." << endl;
		}
		else {
			cout << "Non-symmetric." << endl;
		}
	}
	return 0;
}
