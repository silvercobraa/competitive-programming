#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		int s, d;
		cin >> s >> d;
		int a = (s + d)/2;
		int b = s - a;
		if (a + b != s or a - b != d or a < 0 or b < 0) {
			puts("impossible");
		}
		else {
			printf("%d %d\n", a, b);
		}
	}
	return 0;
}
