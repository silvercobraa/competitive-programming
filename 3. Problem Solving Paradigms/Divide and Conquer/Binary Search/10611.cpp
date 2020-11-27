#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> v(n);
	for (size_t i = 0; i < n; i++) {
		cin >> v[i];
	}
	int q;
	cin >> q;
	for (size_t i = 0; i < q; i++) {
		int h;
		cin >> h;
		// cout << "h:" << h << endl;
		auto lower = lower_bound(v.begin(), v.end(), h);
		auto upper = upper_bound(v.begin(), v.end(), h);
		if (lower != v.begin()) {
			--lower;
			cout << *lower;
		}
		else {
			cout << 'X';

		}
		cout << " ";
		if (upper != v.end()) {
			cout << *upper;
		}
		else {
			cout << 'X';

		}
		cout << endl;
	}

	return 0;
}
