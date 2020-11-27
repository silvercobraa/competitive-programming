#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	while (cin >> n) {
		int size = 1 << n;
		vector<int> w(size);
		vector<int> pot(size, 0);
		for (int i = 0; i < size; i++) {
			cin >> w[i];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < n; j++) {
				int idx = i ^ (1 << j);
				pot[i] += w[idx];
			}
		}
		int sum = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < n; j++) {
				int idx = i ^ (1 << j);
				sum = max(sum, pot[i] + pot[idx]);
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
