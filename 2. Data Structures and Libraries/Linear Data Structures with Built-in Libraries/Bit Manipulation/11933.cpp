#include <iostream>

using namespace std;

void split(int n) {
	int a = 0;
	int b = 0;
	int odd = 1;
	for (int bit = 0; bit < 31; bit++) {
		int mask = 1 << bit;
		if (n & mask) {
			if (odd) {
				a |= mask;
			}
			else {
				b |= mask;
			}
			odd = 1 - odd;
		}
	}
	printf("%d %d\n", a, b);
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		split(n);
	}
	return 0;
}
