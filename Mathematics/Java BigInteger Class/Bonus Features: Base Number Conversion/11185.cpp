#include <iostream>

using namespace std;

int ternary(int x) {
	if (x < 3) {
		printf("%d", x);
		return x;
	}
	int rec = ternary(x / 3);
	printf("%d", x % 3);
	return rec;
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n >= 0; cin >> n) {
		ternary(n);
		puts("");
	}
	return 0;
}
