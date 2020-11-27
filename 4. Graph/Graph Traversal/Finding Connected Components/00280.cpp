#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		// cout << n << endl;
		vector<vector<int>> connected(n, vector<int>(n, false));
		int a;
		for (cin >> a; a != 0; cin >> a) {
			int b;
			for (cin >> b; b != 0; cin >> b) {
				connected[a-1][b-1] = true;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					connected[i][j] = connected[i][j] | (connected[i][k] & connected[k][j]);
				}
			}
		}
		int q;
		cin >> q;
		// cout << "q:" << q << endl;
		for (size_t i = 0; i < q; i++) {
			int start;
			cin >> start;
			int total = 0;
			for (int i = 0; i < n; i++) {
				total += not connected[start-1][i];
			}
			cout << total;
			for (int i = 0; i < n; i++) {
				if (not connected[start-1][i]) {
					cout << " " << i+1;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
