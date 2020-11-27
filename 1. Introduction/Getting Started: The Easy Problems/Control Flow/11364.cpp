#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int min = 101;
		int max = -1;
		for (size_t i = 0; i < n; i++) {
			int x;
			cin >> x;
			min = std::min(min, x);
			max = std::max(max, x);
		}
		cout << 2*(max - min) << endl;
	}
	return 0;
}
