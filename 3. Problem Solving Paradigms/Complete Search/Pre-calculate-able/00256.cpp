#include <iostream>

using namespace std;

void search(long long digits) {
	long long power = 1;
	for (long long i = 0; i < digits/2; i++) {
		power *= 10;
	}
	for (long long i = 0; i < power*power; i++) {
		long long low = i/power;
		long long high = i%power;
		if ((low+high)*(low+high) == i) {
			if (digits == 2) {
				printf("%02d\n", i);
			}
			else if (digits == 4) {
				printf("%04d\n", i);
			}
			else if (digits == 6) {
				printf("%06d\n", i);
			}
			else if (digits == 8) {
				printf("%08d\n", i);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	while (cin >> n) {
		search(n);
	}
	return 0;
}
