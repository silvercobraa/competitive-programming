#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int Y;
	while (cin >> Y) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (size_t i = 0; i < n; i++) {
			cin >> v[i];
		}
		int best_len = 0;
		int left = -1;
		int right = -1;
		for (int i = 0; i < n; i++) {
			int start = v[i];
			int end = start + Y - 1;
			auto upper = upper_bound(v.begin(), v.end(), end);
			int j = distance(v.begin(), upper);
			int length = j - i;
			if (upper != v.end() and length > best_len) {
				// cout << length << " " << i << " " << j << endl;
				// cout << v[i] << " " << v[j] << endl;
				best_len = length;
				left = v[i];
				right = v[j - 1];
			}
		}
		cout << best_len << " " << left << " " << right << endl;
	}
	return 0;
}
