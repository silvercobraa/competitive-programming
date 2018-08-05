#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int res = ((((n*567) / 9) + 7492)*235) / 47 - 498;
		res = res < 0 ? -res : res;
		cout << (res / 10) % 10 << endl;
	}
	return 0;
}
