#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	constexpr int MAX = 60000;
	vector<int> sum(MAX+1, 1);
	for (int i = 2; i <= MAX; i++) {
		for (int j = 2; j*2 <= i; j++) {
			if (i % j == 0) {
				sum[i] += j;
				if (sum[i] > i) {
					break;
				}
			}
		}
	}
	sum[1] = 0;
	int n;
	puts("PERFECTION OUTPUT");
	for (cin >> n; n != 0; cin >> n) {
		if (sum[n] == n) {
			printf("%5d  PERFECT\n", n);
		}
		else if (sum[n] < n) {
			printf("%5d  DEFICIENT\n", n);
		}
		else {
			printf("%5d  ABUNDANT\n", n);
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
