#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int64_t n, m;
		cin >> n >> m;
		if (n < m) {
			cout << '<' << endl;
		}
		else if (n > m) {
			cout << '>' << endl;
		}
		else {
			cout << '=' << endl;
		}
	}
	return 0;
}
