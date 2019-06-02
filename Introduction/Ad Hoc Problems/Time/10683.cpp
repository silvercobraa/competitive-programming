#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	// el factor de conversión es (num/den)
	int num = (5)*(5)*(5); // 10 * 100 * 100 * 100
	int den = (3)*(2*3)*(2*3); // 24 * 60 * 60 * 100
	while (cin >> t) {
		int h, m, s, c;
		c = t % 100; t /= 100;
		s = t % 100; t /= 100;
		m = t % 100; t /= 100;
		h = t;
		int ans = 100*(60*(60*h + m) + s) + c;
		printf("%07d\n", num*ans/den);
	}
	return 0;
}
