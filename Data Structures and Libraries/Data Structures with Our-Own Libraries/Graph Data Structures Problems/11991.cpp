#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	while (cin >> n >> m) {
		map<int, vector<int>> g;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			g[x].push_back(i);
		}
		// for (auto p: g) {
		// 	cout << p.first << ":";
		// 	for (auto x: p.second) {
		// 		cout << " " << x;
		// 	}
		// 	cout << endl;
		// }
		for (int i = 1; i <= m; i++) {
			int index, value;
			cin >> index >> value;
			if (g.find(value) != g.end() and index - 1 < g[value].size()) {
				cout << g[value][index-1] << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
