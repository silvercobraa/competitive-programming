#include <iostream>

using namespace std;

int f(int n) {
	int sum = 0;
	for ( ; n != 0; n /= 10) {
		sum += n % 10;
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		int sum = n;
		for ( ; n >= 10; n = f(n)) {
		}
		cout << n << endl;
	}
	return 0;
}
