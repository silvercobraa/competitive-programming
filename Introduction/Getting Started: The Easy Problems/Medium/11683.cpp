#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int A;
	int C;
	for (cin >> A >> C; A != 0; cin >> A >> C) {
		int count = 0;
		int h = A;
		for (size_t i = 0; i < C; i++) {
			int x;
			cin >> x;
			if (x < h) {
				// cout << "h - x" << h - x << endl;
				count += h - x;
			}
			h = x;
		}
		cout << count << endl;
	}
	return 0;
}
