#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;

	for (int count = 1; true; count++) {
		vector<int> v;
		for (cin >> n; n != -1; cin >> n) {
			v.push_back(n);
		}
		// cout << v.size() << endl;
		if (v.empty()) {
			break;
		}
		if (count != 1) {
			cout << endl;
		}
		// longest decreasing subsequence? xd
		vector<int> lds(v.size(), 1);
		int best = 1;
		for (int i = 1; i < lds.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (v[j] >= v[i]) {
					lds[i] = max(lds[i], lds[j] + 1);
				}
			}
			best = max(best, lds[i]);
		}
		printf("Test #%d:\n", count);
		printf("  maximum possible interceptions: %d\n", best);
	}
	return 0;
}
