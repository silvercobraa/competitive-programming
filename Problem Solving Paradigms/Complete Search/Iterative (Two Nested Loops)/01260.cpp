#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n;
		cin >> n;
		std::vector<int> a(n);
		int total_b = 0;
		cin >> a[0];
		for (int i = 1; i < n; i++) {
			cin >> a[i];
			for (size_t j = 0; j < i; j++) {
				total_b += a[j] <= a[i];
			}
		}
		cout << total_b << endl;
	}
	return 0;
}
