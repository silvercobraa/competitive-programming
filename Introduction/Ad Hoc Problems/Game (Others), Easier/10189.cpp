#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	int cas = 1;
	for (cin >> n >> m; n != 0 or m != 0; cin >> n >> m, cas++) {
		if (cas != 1) {
			cout << endl;
		}
		vector<string> field(n);
		for (size_t i = 0; i < n; i++) {
			cin >> field[i];
		}
		cout << "Field #" << cas << ":" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == '*') {
					cout << "*";
					continue;
				}
				int count = 0;
				for (int row = i - 1; row <= i + 1; row++) {
					if (row < 0 or row >= n) {
						continue;
					}
					for (int col = j - 1; col <= j + 1; col++) {
						if (col < 0 or col >= m or (row == i and col == j)) {
							continue;
						}
						if (field[row][col] == '*') {
							count++;
						}
					}
				}
				cout << count;
			}
			cout << endl;
		}
	}

	return 0;
}
