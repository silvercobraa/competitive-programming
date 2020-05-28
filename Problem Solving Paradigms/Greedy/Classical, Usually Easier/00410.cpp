#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int C, S;
	int set_count = 1;
	while (cin >> C >> S) {
		vector<int> mass(2*C, 0);
		for (size_t i = 0; i < S; i++) {
			cin >> mass[i];
		}
		sort(mass.begin(), mass.end());
		int sum_chambers = 0;
		for (size_t i = 0; i < 2*C; i++) {
			sum_chambers += mass[i];
		}
		double average = sum_chambers / double(C);
		double imbalance = 0.0;
		printf("Set #%d\n", set_count);
		for (int i = 0; i < C; i++) {
			printf(" %d:", i);
			// printf("\nMASS:%d\n", mass[i]);
			if (mass[i] != 0) {
				printf(" %d", mass[i]);
			}
			if (mass[2*C-i-1] != 0) {
				printf(" %d", mass[2*C-i-1]);
			}
			int sum_chamber = mass[i] + mass[2*C-i-1];
			imbalance += abs(average - sum_chamber);
			puts("");
		}
		printf("IMBALANCE = %.5lf\n\n", imbalance);
		set_count++;
	}
	return 0;
}
