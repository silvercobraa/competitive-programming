#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int k;
	while (cin >> k) {
		vector<pair<int,int>> v;
		for (size_t x = k+1; x <= 2*k; x++) {
		// for (size_t x = k+1; 1; x++) {
			// cout << double(k*x) / (x - k) << endl;
			if ((k*x) % (x - k) == 0) {
				int y = (k*x) / (x - k);
				if (x >= y) {
					v.push_back({x, y});
				}
				else {
					v.push_back({y, x});
				}
			}
		}
		sort(v.rbegin(), v.rend());
		cout << v.size() << endl;
		for (auto p: v) {
			printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
		}
	}
	return 0;
}
