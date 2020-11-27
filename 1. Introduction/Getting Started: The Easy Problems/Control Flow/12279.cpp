#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	int cas = 1;
	for (cin >> n; n != 0; cin >> n, cas++) {
		int zeros = 0;
		int nonzeros = 0;
		for (size_t i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 0) {
				zeros++;
			}
			else {
				nonzeros++;
			}
		}
		cout << "Case " << cas << ": " << nonzeros - zeros << endl;
	}
	return 0;
}
