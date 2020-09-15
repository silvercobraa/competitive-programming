#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 99999999;

int main(int argc, char const *argv[]) {
	int n;
	int count = 1;
	for (cin >> n; n != 0; cin >> n) {
		cout << "Case " << count << ":" << endl;
		vector<int> v(n);
		for (size_t i = 0; i < n; i++) {
			cin >> v[i];
		}
		int m;
		cin >> m;
		for (size_t k = 0; k < m; k++) {
			int sum;
			cin >> sum;
			int distance = INF;
			int closest = INF;
			for (size_t i = 0; i < n; i++) {
				for (size_t j = i + 1; j < n; j++) {
					int d = abs(v[i] + v[j] - sum);
					if (d < distance) {
						distance = d;
						closest = v[i] + v[j];
					}
				}
			}
			printf("Closest sum to %d is %d.\n", sum, closest);
		}
		count++;
	}
	return 0;
}
