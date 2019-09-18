#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	long long int a, b;
	while (cin >> a >> b) {
		long long int c = a - b;
		long long int d = b - a;
		if (c >= 0) {
			cout << c << endl;
		}
		else {
			cout << d << endl;
		}
	}
	return 0;
}
