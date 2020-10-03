#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int gcd(int a, int b) {
	return a%b == 0 ? b : gcd(b, a%b);
}

int digits(int x) {
	int ret = 0;
	for ( ; x != 0; x/= 10) {
		ret++;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	int n;
	int case_ = 1;
	for (cin >> n; n != 0; cin >> n, case_++) {
		int a = 0;
		for (size_t i = 0; i < n; i++) {
			int x;
			cin >> x;
			a += x;
		}
		int c = n;
		bool sign = false;
		if (a < 0) {
			sign = true;
			a = -a;
		}
		int g = gcd(a, c);
		a /= g;
		c /= g;
		int b = a % c;
		a /= c;
		int da = digits(a);
		int db = digits(b);
		int dc = digits(c);
		printf("Case %d:\n", case_);
		// printf("%d %d %d\n", a, b, c);
		if (a == 0 and b == 0) {
			printf("0\n");
			continue;
		}
		if (sign) {
			da += 2;
		}
		if (b != 0) {
			for (int i = 0; i < da; i++) {
				printf(" ");
			}
			for (int i = 0; i < dc - db; i++) {
				printf(" ");
			}
			printf("%d\n", b);
		}
		if (a != 0) {
			if (sign) {
				printf("- %d", a);
			}
			else {
				printf("%d", a);
			}
			if (b != 0) {
				for (int i = 0; i < dc; i++) {
					printf("-");
				}
			}
			printf("\n");
		}
		else {
			if (sign) {
				printf("- ");
			}
			if (b != 0) {
				for (int i = 0; i < dc; i++) {
					printf("-");
				}
			}
			printf("\n");
		}
		if (b != 0) {
			for (int i = 0; i < da; i++) {
				printf(" ");
			}
			printf("%d\n", c);
		}
	}
	return 0;
}
