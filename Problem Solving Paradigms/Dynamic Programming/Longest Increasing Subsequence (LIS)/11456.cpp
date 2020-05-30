#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<int> w(n);
		vector<int> lis(n, 1);
		vector<int> lds(n, 1);
		for (size_t i = 0; i < n; i++) {
			cin >> w[i];
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = n - 1; j > i; j--) {
				if (w[i] >= w[j]) {
					lis[i] = max(lis[i], lis[j] + 1);
				}
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = n - 1; j > i; j--) {
				if (w[i] <= w[j]) {
					lds[i] = max(lds[i], lds[j] + 1);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, lis[i] + lds[i] - 1);
			// cout << lis[i] << " " << lds[i] << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
