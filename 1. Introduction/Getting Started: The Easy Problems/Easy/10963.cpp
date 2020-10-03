#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int n;
		cin >> n;
		vector<int> gap(n);
		for (size_t i = 0; i < n; i++) {
			int y1, y2;
			cin >> y1 >> y2;
			gap[i] = y1 - y2;
		}
		int val = gap[0];
		bool all_equal = true;
		for (size_t j = 0; j < n; j++) {
			if (val != gap[j]) {
				all_equal = false;
				break;
			}
		}
		if (all_equal) {
			puts("yes");
		}
		else {
			puts("no");
		}
	}
	return 0;
}
