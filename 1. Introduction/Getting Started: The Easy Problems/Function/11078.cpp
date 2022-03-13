#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int best_diff = -99999999;
		int cummax = v[0];
		for (int k = 1; k < n; k++) {
			best_diff = max(best_diff, cummax - v[k]);
			cummax = max(cummax, v[k]);
		}
		cout << best_diff << endl;
	}
	return 0;
}
