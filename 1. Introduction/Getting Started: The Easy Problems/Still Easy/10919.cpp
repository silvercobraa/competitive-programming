#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int k, m;
	for (cin >> k >> m; k != 0; cin >> k >> m) {
		vector<int> courses(k);
		for (size_t i = 0; i < k; i++) {
			cin >> courses[i];
		}
		vector<int> minimum(m);
		map<int, vector<int>> cat;
		for (size_t i = 0; i < m; i++) {
			int c, r;
			cin >> c >> r;
			minimum[i] = r;
			for (size_t j = 0; j < c; j++) {
				int x;
				cin >> x;
				cat[x].push_back(i);
			}
		}
		for (size_t i = 0; i < k; i++) {
			for (auto j: cat[courses[i]]) {
				minimum[j]--;
			}
		}
		bool yes = true;
		for (auto x: minimum) {
			if (x > 0) {
				yes = false;
				break;
			}
		}
		if (yes) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}
