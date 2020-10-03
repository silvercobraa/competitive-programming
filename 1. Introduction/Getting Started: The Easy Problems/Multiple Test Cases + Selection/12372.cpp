#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a <= 20 and b <= 20 and c <= 20) {
			cout << "Case " << t + 1 << ": good\n";
		}
		else {
			cout << "Case " << t + 1 << ": bad\n";
		}
	}
	return 0;
}
