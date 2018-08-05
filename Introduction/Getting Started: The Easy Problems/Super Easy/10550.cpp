// problema maricon, las weas estan al reves
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int p, a, b, c;
	while (cin >> p >> a >> b >> c) {
		if (p == 0 and a == 0 and b == 0 and c == 0) {
			break;
		}
		int d1 = (p + 40 - a) % 40;
		int d2 = (b + 40 - a) % 40;
		int d3 = (b + 40 - c) % 40;
		cout << 3*360 + 9*(d1 + d2 + d3) << endl;
	}
	return 0;
}
