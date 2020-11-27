#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int s = 0;
		for (size_t i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			s += a*c;
		}
		cout << s << endl;
	}
	return 0;
}
