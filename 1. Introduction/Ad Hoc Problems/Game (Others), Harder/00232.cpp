#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	int t = 1;
	for (cin >> n >> m; n != 0; cin >> n >> m, t++) {
		if (t != 1) {
			cout << endl;
		}
		vector<string> v(n);
		for (size_t i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		cout << "puzzle #" << t << ":" << endl;
		cout << "Across" << endl;
		int count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] != '*' and (i == 0 or v[i - 1][j] == '*' or j == 0 or v[i][j - 1] == '*')) {
					count++;
					if (!vis[i][j]) {
						cout << setw(3) << count << ".";
						for (int k = j; k < m and v[i][k] != '*'; k++) {
							vis[i][k] = true;
							cout << v[i][k];
						}
						cout << endl;
					}
				}
			}
		}
		vis = vector<vector<bool>>(n, vector<bool>(m, false));
		cout << "Down" << endl;
		count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] != '*' and (i == 0 or v[i - 1][j] == '*' or j == 0 or v[i][j - 1] == '*')) {
					count++;
					if (!vis[i][j]) {
						cout << setw(3) << count << ".";
						for (int k = i; k < n and v[k][j] != '*'; k++) {
							vis[k][j] = true;
							cout << v[k][j];
						}
						cout << endl;
					}
				}
			}
		}
	}
	return 0;
}
